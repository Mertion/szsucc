unit gts_la;

interface

const  GTDll = 'gts.dll';

Const  LA_AXIS_NUM = 8;
Const  LA_WORK_AXIS_NUM = 6;
Const  LA_MACHINE_AXIS_NUM = 5;

Const  AXIS_LIMIT_NONE = 0;       //��������
Const  AXIS_LIMIT_MAX_VEL = 1;       //������ٶ�����
Const  AXIS_LIMIT_MAX_ACC = 2;       //�������ٶ�����
Const  AXIS_LIMIT_MAX_DV = 4;       //������ٶ�����������

Const  KIN_MSG_BUFFER_SIZE = 32;

//��������ϵ�¹켣�Ƿ������ٶ�ģʽ
type EWorkLimitMode = (WORK_LIMIT_INVALID,WORK_LIMIT_VALID);

//���õ��ٶȶ������
type EVelSettingDef = (NORMAL_DEF_VEL,NUM_DEF_VEL,CUT_DEF_VEL);

//���õļ��ٶȶ������
type EAccSettingDef = (NORMAL_DEF_ACC,LONG_AXIS_ACC);

//��������
type EMachineMode = (NORMAL_THREE_AXIS,MULTI_AXES,FIVE_AXIS,FIVE_AXIS_WORK,ROBOT);

//ǰհ�����ṹ��
type TLookAheadParameter = record
    lookAheadNum: LongInt;
    time:Double;
    radiusRatio:Double;
    vMax:array[0..7] of Double;
    aMax:array[0..7] of Double;
    DVMax:array[0..7] of Double;
    scale:array[0..7] of Double;
    axisRelation:array[0..7] of Double;
    machineCfgFileName:String;
end;

type RC_KIN_CONFIG = record
		RobotType:SmallInt;
		reserved1:SmallInt;
		KinParUse:array[0..17] of SmallInt;
		KinPar:array[0..17] of Double;
		KinLimitUse:array[0..11] of SmallInt;
		KinLimitMin:array[0..11] of Double;
		KinLimitMax:array[0..11] of Double;
		KinLimitMinShift:array[0..11] of Double;
		KinLimitMaxShift:array[0..11] of Double;
		AxisUse:array[0..7] of SmallInt;
		AxisPosSignSwitch:String;
		AxisPosOffset:array[0..7] of SmallInt;
		CartUnitUse:array[0..5] of SmallInt;
		CartPosKCSSignSwitch:String;
		reserved2:array[0..2] of SmallInt;
		CartPosKCSOffset:array[0..5] of Double;
end;

type RC_ERROR_INTERFACE = record
		Error:ShortInt;
		ErrorID:SmallInt;
		Message:String;
end;

type RC_MSG_BUFFER_ELEMENT = record  
		ErrorID:SmallInt;
		Message:String;
		LogTime:String;
		InternalID:LongInt;
end;

type RC_MSG_BUFFER = record
		LastMsgIndex:SmallInt;
		MsgElement:array[0..31] of RC_MSG_BUFFER_ELEMENT;
		LastMsgID:LongInt;
end;

//��ת�᷶Χ����
type TRotationAxisRange = record
		primaryAxisRangeOn:LongInt;              //��һ��ת���޶���Χ�Ƿ���Ч��0������Ч��1����Ч
		slaveAxisRangeOn:LongInt;                //�ڶ���ת���޶���Χ�Ƿ���Ч��0������Ч��1����Ч
		maxPrimaryAngle:Double;              //��һ��ת�����ֵ
		minPrimaryAngle:Double;              //��һ��ת����Сֵ
		maxSlaveAngle:Double;                //�ڶ���ת�����ֵ
		minSlaveAgnle:Double;                //�ڶ���ת����Сֵ
end;

//ѡ�����
type EGroupSelect = (Continuous,Group_1,Group_2);

type TPos = record
		machinePos:array[0..4] of Double;
		workPos:array[0..5] of Double;
end;

//�ٶȹ滮ģʽ
type EVelMode = (T_CURVE,S_CURVE,S_CURVE_NEW,VEL_MODE_MAX);

type OptimizeState = (OPT_OFF, OPT_ON);
type OptimizeMethod = (NO_OPT, OPT_BLENDING, OPT_CIRCLEFITTING, OPT_CUBICSPLINE, OPT_BSPLINE);

type ErrorID = (INIT_ERROR=1,		//û�н��в�����ʼ��
			PASSWORD_ERROR,		//����������ڹ̸��˶�����ƽ̨������
			INDATA_ERROR,		//�������ݴ��󣨼��Բ�������Ƿ���ȷ��
			PRE_PROCESS_ERROR,	//
			TOOL_RADIUS_COMPENSATE_ERROR_INOUT,		//���߰뾶�������󣺽���/����������������Բ��
			TOOL_RADIUS_COMPENSATE_ERROR_NOCROSS,	//���߰뾶�����������ݲ������޷����㽻��
			USERDATA_ERROR,
);

//�켣�Ż������ṹ��
type TOptimizeParamUser = record 
		usePathOptimize:OptimizeState;	//�Ƿ�ʹ��·���Ż���OPT_OFF:��ʹ��	OPT_ON:ʹ��
		tolerance:Single;								//����(suggest: rough:0.1, pre-finish:0.05, finish:0.01)
		optimizeMethod:OptimizeMethod;	//ѡ�������Ż���ʽ
		keepLargeArc:OptimizeState;			//�Ƿ�����Բ����OPT_OFF���������� OPT_ON������
		blendingMinError:Single;				//blending����С�趨���
		blendingMaxAngle:Single;				//blending�����Ƕ����ƣ������߶������Ƕȴ��ڸýǶ�ʱ������blending����λ���ȣ�
end;

type TErrorInfo = record 
		 errorID:ErrorID;		//�����(INIT_ERROR:δ��ʼ��������PRE_PROCESS_ERROR:Ԥ����ģ�����
												//TOOL_RADIUS_COMPENSATE_ERROR:���߰뾶��������	
		errorRowNum:LongInt;		//�����к�
end;

type TPreStartPos = record 
		Pos:array[0..7] of Double;
end;

type TBufIoDelayData = record  
		doType:Word;
		doMask:Word;
		doValue:Word;
		delayTime:Word;
		fifo:SmallInt;
end;

type TBufDoBitPulseData = record  
		doType:SmallInt;
		doIndex:SmallInt;
		highLevelTime:Word;
		lowLevelTime:Word;
		pulseNum:LongInt;
		firstLevel:SmallInt;
		fifo:SmallInt;
end;

type TBufDaData = record  
		channel:SmallInt;
		daValue:SmallInt;
		fifo:SmallInt;
end;

type TBufLaserData = record  
		channel:SmallInt;
		fifo:SmallInt;
		source:SmallInt;
		laserPower:Double;
		ratio:Double;
		minPower:Double;
		maxPower:Double;
		tableId:SmallInt;
end;

type TBufGearData = record  
		axis:SmallInt;
		deltaPos:Double;
		fifo:SmallInt;
		smoothFlag:SmallInt;
		accPercent:SmallInt;
		decPercent:SmallInt;
end;

type TBufMoveData = record  
		axis:SmallInt;
		pos:Double;
		vel:Double;
		acc:Double;
		modal:SmallInt;
		fifo:SmallInt;
end;

type TBufSegNumData = record
		segNum:LongInt;
		fifo:SmallInt;
end;

type TBufFollowMasterData = record  
		crdAxis:SmallInt;
		masterIndex:SmallInt;
		masterType:SmallInt;
		fifo:SmallInt;
end;

type TBufFollowEventCrossData = record  
		masterPos:LongInt;
		pad:LongInt;
		fifo:SmallInt;
end;

type TBufFollowEventTriggerData = record
		triggerIndex:SmallInt;
		triggerOffset:LongInt;
		pad:LongInt;
		fifo:SmallInt;
end;

type TBufFollowStartData = record
		masterSegment;
		slaveSegment;
		masterFrameWidth;
		fifo:SmallInt;
end;

type TBufFollowNextData = record
		width:LongInt;
		fifo:SmallInt;
end;

type TBufFollowReturnData = record
		vel:Double;
		acc:Double;
		smoothPercent:SmallInt;
		fifo:SmallInt;
end;

type TBufSmartCutterData = record  
		index:SmallInt;
		enable:SmallInt;
		fifo:SmallInt;
end;

type TBufEventData = record
		eventIndex:SmallInt;
		count:SmallInt;
		fifo:SmallInt;
end;

function GT_SetupLookAheadCrd(cardNum:SmallInt ;crd:SmallInt;machineMode:EMachineMode):SmallInt;stdcall;External GTDLL;
function GT_SetFollowAxisParaLa(cardNum:SmallInt ;crd:SmallInt;var pAxisLimitMode:SmallInt;var pVmax:Double;var pAmax:Double;var pDVmax:Double):SmallInt;stdcall;External GTDLL;
function GT_SetVelDefineModeLa(cardNum:SmallInt ;crd:SmallInt;velDefMode:EVelSettingDef):SmallInt;stdcall;External GTDLL;
function GT_SetAxisLimitModeLa(cardNum:SmallInt ;crd:SmallInt;var pAxisLimitMode:LongInt):SmallInt;stdcall;External GTDLL;
function GT_SetWorkLimitModeLa(cardNum:SmallInt ;crd:SmallInt;workLimitMode:EWorkLimitMode):SmallInt;stdcall;External GTDLL;
function GT_SetAxisVelValidModeLa(cardNum:SmallInt ;crd:SmallInt;velValidAxis:LongInt):SmallInt;stdcall;External GTDLL;
function GT_SetVelSmoothMode(cardNum:SmallInt ;crd:SmallInt;smoothMode:LongInt):SmallInt;stdcall;External GTDLL;
function GT_SetArcAllowErrorLa(cardNum:SmallInt ;crd:SmallInt;error:Double):SmallInt;stdcall;External GTDLL;
function GT_InitLookAheadEx(cardNum:SmallInt ;crd:SmallInt;var pLookAheadPara:TLookAheadParameter;fifo:SmallInt = 0;motionMode:SmallInt = 0;var pPreStartPos:LongInt = 0):SmallInt;stdcall;External GTDLL;
function GT_PrintLACmdLa(cardNum:SmallInt ;crd:SmallInt;printFlag:LongInt;clearFile:LongInt):SmallInt;stdcall;External GTDLL;

function GT_LnXYEx(cardNum:SmallInt ;crd:SmallInt ;x:Double ;y:Double ;synVel:Double ;synAcc:Double ;segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_LnXYG0Ex(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;synVel:Double ;synAcc:Double ;segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;

function GT_LnXYZEx(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;z:Double;synVel:Double ;synAcc:Double ; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_LnXYZG0Ex(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;z:Double;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;

function GT_LnXYZAEx(cardNum:SmallInt ;crd:SmallInt ;x:Double; y:Double;z:Double;a:Double;synVel:Double ;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_LnXYZAG0Ex(cardNum:SmallInt ;crd:SmallInt ;x:Double;y:Double;z:Double;a:Double;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;

function GT_LnXYZACEx(cardNum:SmallInt ;crd:SmallInt ;var pPos:Double; posMask:SmallInt;synVel:Double ;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_LnXYZACG0Ex(cardNum:SmallInt ;crd:SmallInt ;var pPos:Double; posMask:SmallInt;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;

function GT_LnXYZACUVWEx(cardNum:SmallInt ;crd:SmallInt ;var pPos:Double; posMask:SmallInt;synVel:Double ;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_LnXYZACUVWG0Ex(cardNum:SmallInt ;crd:SmallInt ;var pPos:Double; posMask:SmallInt;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;

function GT_ArcXYREx(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;radius:Double;circleDir:SmallInt;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_ArcYZREx(cardNum:SmallInt ;crd:SmallInt;y:Double;z:Double;radius:Double;circleDir:SmallInt ;synVel:Double ;synAcc:Double ; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_ArcZXREx(cardNum:SmallInt ;crd:SmallInt;z:Double;x:Double;radius:Double;circleDir:SmallInt ;synVel:Double ;synAcc:Double ; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;

function GT_ArcXYCEx(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;xCenter:Double;yCenter:Double ;circleDir:SmallInt ;synVel:Double ;synAcc:Double ; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_ArcYZCEx(cardNum:SmallInt ;crd:SmallInt;y:Double;z:Double;yCenter:Double;zCenter:Double ;circleDir:SmallInt ;synVel:Double ;synAcc:Double ; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_ArcZXCEx(cardNum:SmallInt ;crd:SmallInt;z:Double;x:Double;zCenter:Double;xCenter:Double ;circleDir:SmallInt ;synVel:Double ;synAcc:Double ; segNum:LongInt; override2:SmallInt; fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;

function GT_ArcXYZEx(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;z:Double;interX:Double;interY:Double;interZ:Double;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall

function GT_HelixXYRZEx(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;z:Double;radius:Double;circleDir:SmallInt;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_HelixXYCZEx(cardNum:SmallInt ;crd:SmallInt;x:Double;y:Double;z:Double;xCenter:Double;yCenter:Double;circleDir:SmallInt;synVel:Double;synAcc:Double; segNum:LongInt; override2:SmallInt; fifo:SmallInt=0): SmallInt; stdcal

function GT_BufDelayEx(cardNum:SmallInt ;crd:SmallInt;delayTime:Word;fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufGearEx(cardNum:SmallInt ;crd:SmallInt;gearAxis:SmallInt;pos:LongInt;fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufGearPercentEx(cardNum:SmallInt ;crd:SmallInt;gearAxis:SmallInt;pos:LongInt;accPercent:SmallInt;decPercent:SmallInt;fifo:
function GT_BufMoveEx(cardNum:SmallInt ;crd:SmallInt;moveAxis:SmallInt;pos:LongInt;vel:Double;acc:Double;modal:SmallInt;fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufIOEx(cardNum:SmallInt ;crd:SmallInt;doType:Word ;doMask:Word ;doValue:Word ;fifo:SmallInt =0): SmallInt; stdcall; External GTDLL;
function GT_BufDAEx(cardNum:SmallInt ;crd:SmallInt;chn:SmallInt;daValue:SmallInt;fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_SetUserSegNumEx(cardNum:SmallInt ;crd:SmallInt;segNum:LongInt;fifo:SmallInt = 0):SmallInt;stdcall;External GTDLL;

function GT_BufLaserOnEx(cardNum:SmallInt ;crd:SmallInt;fifo:SmallInt=0;channel:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufLaserOffEx(cardNum:SmallInt ;crd:SmallInt;fifo:SmallInt=0;channel:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufLaserPrfCmdEx(cardNum:SmallInt ;crd:SmallInt;laserPower:Double;fifo:SmallInt=0;channel:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufLaserFollowRatioEx(cardNum:SmallInt ;crd:SmallInt;ratio:Double;minPower:Double;maxPower:Double;fifo:SmallInt=0;channel:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufLaserFollowModeEx(cardNum:SmallInt ;crd:SmallInt;source:SmallInt =0;fifo:SmallInt=0;channel:SmallInt=0;startPower:Double =0): SmallInt; stdcall; External GTDLL;
function GT_BufLaserFollowSplineEx(cardNum:SmallInt ;crd:SmallInt;tableId:SmallInt=0;minPower:Double;maxPower:Double;fifo:SmallInt=0,channel:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufLaserFollowOffEx(cardNum:SmallInt ;crd:SmallInt;fifo:SmallInt=0;channel:SmallInt=0): SmallInt; stdcall; External GTDLL;

function GT_BufDisableDoBitPulseEx(cardNum:SmallInt ;crd:SmallInt;doType:SmallInt;doIndex:SmallInt;fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;
function GT_BufEnableDoBitPulseEx(cardNum:SmallInt ;crd:SmallInt;doType:SmallInt;doIndex:SmallInt;highLevelTime:Word;lowLevelTime:Word;pulseNum:LongInt;firstLevel:SmallInt;fifo:SmallInt=0): SmallInt; stdcall; External GTDLL;

function GT_CrdDataEx(cardNum:SmallInt ;crd:SmallInt;var pCrdData:TCrdData; fifo:SmallInt = 0):SmallInt;stdcall;External GTDLL;
function GT_CrdDataExEx(cardNum:SmallInt ;crd:SmallInt;var pCrdData:TCrdData; fifo:SmallInt = 0):SmallInt;stdcall;External GTDLL;
function GT_GetLookAheadSegCountEx(cardNum:SmallInt ;crd:SmallInt;out pSegCount:LongInt; fifo:SmallInt = 0):SmallInt;stdcall;External GTDLL;

implementation

end.