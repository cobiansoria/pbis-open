�V���b�s���O�T���v��
====================


[1] �T�v: 

  ���̃f�B���N�g���ɂ́A�P�������� B2C-EC �� SOAP �ōs���V���b�s���O Web 
  �T�[�r�X�̃N���C�A���g����уT�[�r�X�̃T���v���R�[�h���܂܂�Ă��܂��B

  �V���b�s���O Web �T�[�r�X�́A�ȉ��� 4 �̃��\�b�h����\������܂��B

  ���\�b�h��       �Ӗ�          �p�����[�^1   �p�����[�^2   �Ԃ�l
  ---------------  ------------  ------------  ------------  --------------
  GetProductCount  ���i�퐔�擾  (�Ȃ�)        (�Ȃ�)        ���i�퐔
  GetProductSpec   ���i���׎擾  �C���f�b�N�X  (�Ȃ�)        ���i����
  GetStockQty      �݌ɐ��擾    ���i�R�[�h    (�Ȃ�)        ���i�݌ɐ�
  PlaceOrder       ����          ���i�R�[�h    ��          ���������^���s

  �e���\�b�h�̃��N�G�X�g�^���X�|���X���b�Z�[�W�̗�́ASampleMessages
  �f�B���N�g���̊e�t�@�C�����Q�Ƃ��Ă��������B

  �N���C�A���g�v���O�����ł́AGetProductCount �� GetProductSpec ��g��
  ���킹�� GetProductList �Ƃ������\�b�h�ŏ��i���X�g�̎擾���s���Ă��܂��B


[2] ���s�t�@�C���̍쐬:

  OpenSOAP API �C���X�g�[����A2�̂����ꂩ�� make �t�@�C����p���āA
  make -f �t�@�C���� �ŁA���ꂼ��ȉ��̎��s�t�@�C�����쐬����܂��B
  
  (1) Shopping.mak  --- �����E�񓯊���
      (PlaceOrder �̂ݓ������񓯊��Ŏ��s�ł��܂�)

    * ShoppingService
      �W�����o�͂�p�����V���b�s���O�T�[�r�X�v���O�����ł��B

    * ShoppingService.cgi
      CGI �^�̃V���b�s���O�T�[�r�X�v���O�����ł��B

    * ShoppingClient
      �����ŃV���b�s���O�N���C�A���g�v���O�����ł��B

    * ShoppingClientAsync
      PlaceOrder�̂ݔ񓯊������Ή��̃V���b�s���O�N���C�A���g�v���O�����B
	  OpenSOAP�T�[�o�o�R�ŃT�[�r�X���Ăяo�����ɔ񓯊����������s�ł��܂��B

  (2) ShoppingSec.mak   --- �Z�L�����e�B��
      (PlaceOrder �݈̂Í����E�����t�����Ď��s���܂�)

    * ShoppingServiceSec
      �W�����o�͂�p�����Z�L�����e�B�ŃV���b�s���O�T�[�r�X�v���O�����ł��B

    * ShoppingServiceSec.cgi
      CGI �^�̃Z�L�����e�B�ŃV���b�s���O�T�[�r�X�v���O�����ł��B

    * ShoppingClientSec
      �Z�L�����e�B�ŃV���b�s���O�N���C�A���g�v���O�����ł��B

    * ShoppingClientSec.cgi
      CGI �^�̃Z�L�����e�B�ŃV���b�s���O�N���C�A���g�v���O�����ł��B

  
[3] �C���X�g�[��:
  
  �v���O�����t�@�C���A�ݒ�t�@�C���A�f�[�^�t�@�C�����͓K�؂ȏꏊ��
  �C���X�g�[������K�p������܂��B
  
  �����̎��s���ł́Amake -f �t�@�C���� install �œK�؂ȏꏊ��
  �C���X�g�[������܂��B
  
  �ڂ����͂��ꂼ��� make �t�@�C�����Q�Ƃ��Ă��������B
  
  
[4] ���s:

  �T���v���̎��s�̎d�����́A���ꂼ��� make �t�@�C�����Q�Ƃ��Ă��������B
  make �t�@�C���̌㕔�Ɏ��s�Ⴊ���[���Ƃ��ċL�q���Ă���܂��B

  make -f Shopping.mak *test*

    �T���v�����N�G�X�g���b�Z�[�W���g�����T�[�r�X�̃e�X�g
    (���[��)(����)         (�g�p�T�[�r�X���\�b�h��)
    stest1  ���i�퐔�擾   GetProductCount
    stest2  ���i���׎擾   GetProductSpec
    stest3  �݌ɐ��擾     GetStockQty
    stest4  ����           PlaceOrder

    stest5  ���i�퐔�擾   GetProductCount (���s��)
    stest6  ���i���׎擾   GetProductSpec  (���s��)
    stest7  �݌ɐ��擾     GetStockQty     (���s��)
    stest8  ����           PlaceOrder      (���s��)

    �N���C�A���g�̃e�X�g
    ctest1 �S���i���׎擾  GetProductCount + GetProductSpec
    ctest2 �݌ɐ��擾      GetStockQty
    ctest3 ����            PlaceOrder
    ctest1a  (ctest1�̔񓯊��ŃN���C�A���gShoppingClientAsync�ł̃e�X�g)
    ctest2a  (ctest2�� �V )
    ctest3a  (ctest3�� �V )

    �N���C�A���g�̃e�X�g(OpenSOAP�T�[�o�o�R)
    cstest1 ShoppingClient�őS���i���׎擾 GetProductCount + GetProductSpec
    cstest2 ShoppingClient�ō݌ɐ��擾     GetStockQty
    cstest3 ShoppingClient�œ��������ł̔��� PlaceOrder

    cstest1a ShoppingClientAsync�őS���i���׎擾 GetProductCount + GetProductSpec
            �i�����������Ȃ̂�cstest1�Ɠ��������j
    cstest2a ShoppingClientAsync�ō݌ɐ��擾     GetStockQty
            �i�����������Ȃ̂�cstest2�Ɠ��������j
    cstest3a ShoppingClientAsync�œ��������ł̔��� PlaceOrder
    cstest4a ShoppingClientAsync�Ŕ񓯊������ł̔��� PlaceOrderAsync
    cstest5a cstest4a�̏������ʂ̎擾    ConfirmOrder

  make -f ShoppingSec.mak *test*

    �T���v�����N�G�X�g���b�Z�[�W���g�����T�[�r�X�̃e�X�g
    stest1  ���i�퐔�擾   GetProductCount
    stest2  ���i���׎擾   GetProductSpec
    stest3  �݌ɐ��擾     GetStockQty
    stest4  ����           PlaceOrder

    �N���C�A���g�̃e�X�g
    ctest1 �S���i���׎擾  GetProductCount + GetProductSpec
    ctest2 �݌ɐ��擾      GetStockQty
    ctest3 ����            PlaceOrder
  
    �N���C�A���g�̃e�X�g(OpenSOAP�T�[�o�o�R)
    cstest1 �S���i���׎擾 GetProductCount + GetProductSpec
    cstest2 �݌ɐ��擾     GetStockQty
    cstest3 ����           PlaceOrder     

  �Z�L�����e�B�ł̂݁AWeb �A�v���P�[�V�����ŃN���C�A���g
  ShoppingClientSec.cgi ������AWeb �u���E�U�Ŏ��s�ł��܂��B

  Web �u���E�U�œ��͂��� URL �́A���Ƃ��Έȉ��̂悤�ɂȂ�܂��B

  http://localhost/cgi-bin/ShoppingClientSec.cgi