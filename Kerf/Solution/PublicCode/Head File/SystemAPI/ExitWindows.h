#pragma region 

#pragma region 
#pragma warning(disable:4996)



//�˳�ϵͳ
//ReSetWindows(EWX_LOGOFF, false);//ע��
//ReSetWindows(EWX_REBOOT, true);//����
//ReSetWindows(EWX_SHUTDOWN, true);//�ػ�
BOOL ReSetWindows(DWORD dwFlags, BOOL bForce);


//����ϵͳȨ��
BOOL EnableShutDownPriv();
