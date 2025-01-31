#include"GAME14.h"
#include"CONTAINER.h"
#include "REEL_MAP.h"
#include<fstream>
#include<sstream>
#include<vector>
namespace GAME14 {
    REEL_MAP::REEL_MAP(class GAME* game):
        GAME_OBJECT(game){}
    REEL_MAP::~REEL_MAP(){
        delete[] Map.reelData;
        for (int i = 0; i < LOTTERY::NUM_RESULT; i++) {
            delete[] Control_Data[i].normalBuffer ;
            delete[] Control_Data[i].R_BB_Buffer ;
            delete[] Control_Data[i].B_BB_Buffer ;
            delete[] Control_Data[i].REG_Buffer ;
        }
        
        for (int i = 0; i < LOTTERY::NUM_RESULT * NUM_POS; i++) {
            delete[] Second_Control_Data[i].normalBuffer;
            delete[] Second_Control_Data[i].R_BB_Buffer;
            delete[] Second_Control_Data[i].B_BB_Buffer;
            delete[] Second_Control_Data[i].REG_Buffer;

        }
        
    }
    void REEL_MAP::create(){
        Map = game()->container()->data().map;
        ControlDatacreate();
    }
    void REEL_MAP::ControlDatacreate() {
        for (int i = 0; i < LOTTERY::NUM_RESULT; i++) {
            Control_Data[i].normalBuffer = new int[Map.rows];
            Control_Data[i].R_BB_Buffer = new int[Map.rows];
            Control_Data[i].B_BB_Buffer = new int[Map.rows];
            Control_Data[i].REG_Buffer = new int[Map.rows];
        }
        for (int i = 0; i < LOTTERY::NUM_RESULT*NUM_POS; i++) {
            Second_Control_Data[i].normalBuffer = new int[Map.rows];
            Second_Control_Data[i].R_BB_Buffer = new int[Map.rows];
            Second_Control_Data[i].B_BB_Buffer = new int[Map.rows];
            Second_Control_Data[i].REG_Buffer = new int[Map.rows];

        }
    }

    void REEL_MAP::init(){
        initmap();
        initreelMap();
        initfirstreelControl();
        initsecondreelControl();
        initStopPos_NO_Bonus();
        initStopPos_Bonus();

   }
    void REEL_MAP::initmap() {
        StopId["top"] = TOP;
        StopId["middle"] = MID;
        StopId["bottom"] = BOT;
        StopId["NO"] = NO_POS;
    }

   void REEL_MAP::initreelMap() {
       std::stringstream buffer;//string�ɕϊ����邽�߂̃o�b�t�@
       std::string str;
       std::string resultStr;
       std::ifstream file;
       Map.reelData = new int[Map.rows * Map.cols + 2];
       file.open(Map.reelMapFile, std::ios::binary);
       if (!file) {
           file.close();
           WARNING(1, "���[���}�b�v���J���܂���ł���", Map.reelMapFile);
       }
       buffer << file.rdbuf();
       file.close();
       str = buffer.str();
       buffer.str("");
       int cntCol = 0;
       for (int i = 0; i < str.size(); i++) {
           cntCol++;
           if (str[i] == '\n') {
               if (cntCol != Map.cols) {
                   WARNING(1, "�񐔂��R����Ȃ�", "");
               }
               cntCol = 0;
           }
       }
       if (str.size() % Map.cols != 0) {
           WARNING(1, "�Ōオ���s����Ă��Ȃ�", "");
       }
       int i = 0;
       while (1) {
           if (i >= str.size()) {
               break;
           }
           if (str[i] != '\n') {
               Map.reelData[i] = str[i] - '0';
           }
           i++;

       }



   }
   void REEL_MAP::initfirstreelControl() {
       std::ifstream file;
       std::vector<int> resultId;
       std::string str;
       std::string cutStr;
       std::string::size_type cutPos;
       std::string::size_type startPos;
       int cellNumber = 0;
       int stateId = 0;
       int reelId = 0;
       for (int n = 0; n < NUM_FILE; n++) {
           //�ǂ̏�Ԃ̃��[�����䂩�����߂�
           stateId = n % NUM_FILE;
           //�v�f���̏�����
           resultId.resize(0);
           file.open(Map.controlFile[n], std::ios::binary);
           if (!file) {
               WARNING(1, "control�t�@�C�����J���܂���ł���", Map.controlFile[n]);
           }
           //����n�߂�R�}�ԍ��̏�����
           cellNumber = Map.cellnum - 1;
           while (1) {
               //��s�擾
               std::getline(file, str);
               //���ꂪ�t�@�C���̍Ōォ�H
               if (file.eof()) {
                   break;
               }
               //�����̐؂��莚���̏�����
               startPos = 0;
               cutPos = 0;
               //�����ȊO���當���񂪎n�܂��Ă��邩�H
               if (strcspn(str.c_str(), "1234567890 ")) {
                   while (startPos <= str.length() - 1) {
                       //�؂���ꏊ�擾
                       cutPos = str.find(Map.separator, startPos);
                       //�Z�p���[�^��������Ȃ������炻�̌�̑S�����ǂݍ���
                       if (cutPos == std::string::npos) {
                           cutPos = str.length() - 1;
                       }
                       //�����؂���
                       cutStr = str.substr(startPos, cutPos - startPos);
                       //�؂��菉�߂̈ʒu���Z�p���[�^�̎��̕�����
                       startPos = cutPos + Map.separator.length();
                       //�؂����������̃��U���gID���擾
                       resultId.emplace_back(game()->lottery()->resultId(cutStr));
                   }

               }
               else {
                   //��ԍŏ��Ƀ��U���gID���擾���Ă��邩�H
                   if (resultId.size()) {
                       //�擾�������U���g�̐����̃��[������e�[�u����ǂݍ���
                       for (int j = 0; j < resultId.size(); j++) {
                           //�擾�������U���g���e�[�u�������������H
                           if (startPos >= str.length()) {
                               WARNING(1, "���̐��ƃe�[�u�����������܂���", Map.controlFile[n]);
                           }
                           //�؂���ꏊ�̎擾
                           cutPos = str.find(Map.separator, startPos);
                           //�Z�p���[�^��������Ȃ������炻�̌�̑S�����ǂݍ���
                           if (cutPos == std::string::npos) {

                               cutPos = str.length() - 1;
                           }
                           //�����؂���
                           cutStr = str.substr(startPos, cutPos - startPos);
                           //�؂��菉�߂̈ʒu���Z�p���[�^�̎��̕�����
                           startPos = cutPos + Map.separator.length();
                           //����R�}���̎擾
                           Control_Data[resultId[j]][stateId][cellNumber] = std::stoi(cutStr);
                       }
                       cellNumber--;

                   }
                   else {
                       WARNING(1, "���̋L�q���ŏ��ɂ���܂���", Map.controlFile[n]);

                   }
               }
           }
           file.close();
       }

   }
   void REEL_MAP::initsecondreelControl() {
       std::ifstream file;
       std::vector<int> resultId;
       std::string str;
       std::string cutStr;
       std::string::size_type cutPos;
       std::string::size_type startPos;
       int cellNumber = 0;
       int curPosId = 0;
       int stateId = 0;
       int reelId = 0;
       int numResult = LOTTERY::NUM_RESULT;

       for (int n = 0; n < NUM_SECOND_FILE; n++) {
           //�ǂ̏�Ԃ̃��[�����䂩�����߂�
           stateId = n % ONE_FILES;
           //�����[�����ǂ̈ʒu�̃��[�����䂩
           curPosId = n / ONE_FILES;
           //����n�߂�R�}�ԍ��̏�����
           cellNumber = Map.cellnum - 1;
           //�v�f���̏�����
           resultId.resize(0);
           file.open(Map.secondControlFile[n], std::ios::binary);
           if (!file) {
               WARNING(1, "control�t�@�C�����J���܂���ł���", Map.secondControlFile[n]);
           }
           while (1) {
               //��s�擾
               std::getline(file, str);
               //���ꂪ�t�@�C���̍Ōォ�H
               if (file.eof()) {
                   break;
               }
               //�����̐؂��莚���̏�����
               startPos = 0;
               cutPos = 0;
               //�����ȊO���當���񂪎n�܂��Ă��邩�H
               if (strcspn(str.c_str(), "1234567890 ")) {
                   while (startPos <= str.length() - 1) {
                       //�؂���ꏊ�擾
                       cutPos = str.find(Map.separator, startPos);
                       //�Z�p���[�^��������Ȃ������炻�̌�̑S�����ǂݍ���
                       if (cutPos == std::string::npos) {
                           cutPos = str.length() - 1;
                       }
                       //�����؂���
                       cutStr = str.substr(startPos, cutPos - startPos);
                       //�؂��菉�߂̈ʒu���Z�p���[�^�̎��̕�����
                       startPos = cutPos + Map.separator.length();
                       //�؂����������̃��U���gID���擾
                       resultId.emplace_back(game()->lottery()->resultId(cutStr));
                   }

               }
               else {
                   //��ԍŏ��Ƀ��U���gID���擾���Ă��邩�H
                   if (resultId.size()) {
                       //�擾�������U���g�̐����̃��[������e�[�u����ǂݍ���
                       for (int j = 0; j < resultId.size(); j++) {
                           //�擾�������U���g���e�[�u�������������H
                           if (startPos >= str.length()) {
                               WARNING(1, "���̐��ƃe�[�u�����������܂���", Map.secondControlFile[n]);
                           }
                           //�؂���ꏊ�̎擾
                           cutPos = str.find(Map.separator, startPos);
                           //�Z�p���[�^��������Ȃ������炻�̌�̑S�����ǂݍ���
                           if (cutPos == std::string::npos) {

                               cutPos = str.length() - 1;
                           }
                           //�����؂���
                           cutStr = str.substr(startPos, cutPos - startPos);
                           //�؂��菉�߂̈ʒu���Z�p���[�^�̎��̕�����
                           startPos = cutPos + Map.separator.length();
                           //����R�}���̎擾
                           Second_Control_Data[resultId[j] + (numResult * curPosId)][stateId][cellNumber] = std::stoi(cutStr);
                       }
                       cellNumber--;

                   }
                   else {
                       WARNING(1, "���̋L�q���ŏ��ɂ���܂���", Map.secondControlFile[n]);

                   }
               }
           }
           file.close();
       }

   }
   void REEL_MAP::initStopPos_NO_Bonus() {
       std::ifstream file;
       std::string str;
       std::string cutStr;
       std::string::size_type startPos = 0;
       std::string::size_type cutPos = 0;
       int resultId = -1;
       STOP_ID stopId = NUM_POS;
       int cellNum = 0;
       int i = 0;

       file.open(Map.distinction_NO_BonusFile, std::ios::binary);
       if (!file) {
           file.close();
           WARNING(1, "���[���}�b�v���J���܂���ł���", Map.distinction_NO_BonusFile);

       }
       int kaka;
       while (1) {
           
           std::getline(file, str);
           //���ꂪ�t�@�C���̍Ōォ�H
           if (file.eof()) {
               break;
           }
           kaka = strcspn(str.c_str(), "0123456789");
           //���l�������Ă�����
           if ( kaka< str.length()) {
               if (resultId <0) {
                   file.close();
                   WARNING(1, "�����w�肳��Ă܂���", Map.distinction_NO_BonusFile);
               }
               while (1) {
                   cutPos = str.find(Map.separator, startPos);

                   if (cutPos == std::string::npos) {
                       cutPos = str.length() - 1;
                   }

                   cutStr = str.substr(startPos, cutPos - startPos);
                   startPos = cutPos + Map.separator.length();

                   if (strspn(cutStr.c_str(), "0123456789 ") < cutStr.length()) {
                       std::string::size_type resizePos = cutStr.find(" ");
                       if (resizePos != std::string::npos) {
                           cutStr = cutStr.substr(0, resizePos);
                       }
                       stopId = StopId[cutStr];
                   }
                   else {
                       cellNum = std::stoi(cutStr)-1;
                       if (cellNum > -1) {
                           StopPos_NO_Bonus[resultId].stop[cellNum] = stopId;
                       }
                       
                   }

                   if (startPos >= str.length()) {
                       stopId = NUM_POS;
                       cellNum = 0;
                       startPos = 0;
                       cutPos = 0;
                       break;
                   }
               }
               
           }
           else {
               str = str.substr(0, str.length() - 1);
               resultId = game()->lottery()->resultId(str);
           }
       }
       file.close();
   }
   void REEL_MAP::initStopPos_Bonus(){
       std::ifstream file;
       std::string str;
       std::string cutStr;
       std::string::size_type startPos = 0;
       std::string::size_type cutPos = 0;
       int bonusId = -1;
       STOP_ID stopId = NUM_POS;
       int cellNum = 0;
       int i = 0;

       file.open(Map.distinction_BonusFile, std::ios::binary);
       if (!file) {
           file.close();
           WARNING(1, "���[���}�b�v���J���܂���ł���", Map.distinction_BonusFile);

       }

       while (1) {

           std::getline(file, str);
           //���ꂪ�t�@�C���̍Ōォ�H
           if (file.eof()) {
               break;
           }

           //���l�������Ă�����
           if (strcspn(str.c_str(), "0123456789") < str.length() - 1) {
               if (bonusId < 0) {
                   file.close();
                   WARNING(1, "�����w�肳��Ă܂���", Map.distinction_BonusFile);
               }
               while (1) {
                   cutPos = str.find(Map.separator, startPos);

                   if (cutPos == std::string::npos) {
                       cutPos = str.length() - 1;
                   }

                   cutStr = str.substr(startPos, cutPos - startPos);
                   startPos = cutPos + Map.separator.length();

                   if (strspn(cutStr.c_str(), "0123456789 ") < cutStr.length()) {
                       std::string::size_type resizePos = cutStr.find(" ");
                       if (resizePos != std::string::npos) {
                           cutStr = cutStr.substr(0, resizePos);
                       }
                       stopId = StopId[cutStr];
                   }
                   else {
                       cellNum = std::stoi(cutStr) - 1;
                       if (cellNum > -1) {
                           StopPos_Bonus[bonusId].stop[cellNum] = stopId;
                       }

                   }

                   if (startPos >= str.length()) {
                       stopId = NUM_POS;
                       cellNum = 0;
                       startPos = 0;
                       cutPos = 0;
                       break;
                   }
               }

           }
           else {
               str = str.substr(0, str.length() - 1);
               bonusId = game()->lottery()->bonusId(str);
           }
       }
       file.close();

   }


    int REEL_MAP::tellTableStopCell(int cellId, int reelId) {
        int resultId = game()->lottery()->result();
        if (resultId < 0) {
            return 0;
        }
        int bonusId = game()->lottery()->bonusResult();
        int state = game()->lottery()->state();
        return Control_Data[resultId][bonusId][cellId];
   }
    int REEL_MAP::tellSecondTableStopCell(int cellId, int reelId, int leftCellId) {
        int resultId = game()->lottery()->result();
        if (resultId < 0) {
            return 0;
        }
        int bonusId = game()->lottery()->bonusResult();
        
        int leftCellPos = StopPos_NO_Bonus[resultId][leftCellId];
        CellPos = leftCellPos;
        if (resultId == LOTTERY::Hazure && bonusId > LOTTERY::NO_BONUS) {
            leftCellPos = StopPos_Bonus[bonusId][leftCellId];
        }
        if (leftCellPos) {
            leftCellPos -= 1;
            return Second_Control_Data[resultId + (LOTTERY::NUM_RESULT * leftCellPos)][bonusId][cellId];

        }
        return 0;
    }

   int REEL_MAP::tellStopCell(int cellId,int reelId) {
       int maxMoveRange = game()->reel()->maxMoveRange();
       int resultId = game()->lottery()->result();
       if (resultId < 0) {
           return 0;
       }
       int bonusId = game()->lottery()->bonusResult();
       if (resultId == LOTTERY::Hazure) {
           if (bonusId > 0) {
               return game()->reel()->tellbonusexistcell(bonusId, reelId);
           }
           else {
               for (int i = 0; i <= maxMoveRange; i++) {
                   if (!game()->reel()->checkbonusexist(i, reelId)) {
                       if (!game()->reel()->checkresultexist(i, reelId)) {
                           return i;
                       }
                   }
               }
           }
       }
       else {
           return game()->reel()->tellresultexistcell(resultId, reelId);
       }
   }

   void REEL_MAP::debagDraw() {
        /*
        print(rowLength);
        print(Str.length());
        textSize(10);
        
       
        */
       /*
       for (int j = 0; j < LOTTERY::NUM_RESULT; j++) {

           for (int i = 0; i < Map.rows; i++) {
               if (Control_Data[j][LOTTERY::REGULAR][i] >= 0) {
                   text(Control_Data[j][LOTTERY::REGULAR][i], 50 * j + 500, 40 * i + 60);
               }
           }
       }
       */
       /*
       int ID = LOTTERY::RED_BB;
        for (int j = 0; j < LOTTERY::NUM_RESULT; j++) {

            for (int i = 0; i < Map.rows; i++) {
       fill(0);
                if (Second_Control_Data[j][ID][i] >= 0) {
                    fill(80,80,80);
                }
                   text(Second_Control_Data[j+(LOTTERY::NUM_RESULT*(TOP-1))][ID][i], 50 * j + 500, 40 * i + 60);
            }
        }
        */
        //print("�傫��");
        //print(Control_Data[0].normalBuffer[0]);
       
       
        print("���̎~�܂����ꏊ");
        print(CellPos);
        
        //text(StopPos_Bonus[LOTTERY::RED_BB][0], 1500, 100);

        /*
        print("����R�}��");
        print(StopCell);
       */
       //textSize(50);
       
   }
   int REEL_MAP::textureNum(int reelId, int cellNum) {
        return Map.reelData[((Map.rows-1)-cellNum)*Map.cols+reelId] ;

   }

}