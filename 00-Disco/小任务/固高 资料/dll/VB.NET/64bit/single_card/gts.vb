Module gts
    Public Const DLL_VERSION_0 As Short = 2
    Public Const DLL_VERSION_1 As Short = 1
    Public Const DLL_VERSION_2 As Short = 0
    Public Const DLL_VERSION_3 As Short = 1
    Public Const DLL_VERSION_4 As Short = 5
    Public Const DLL_VERSION_5 As Short = 0
    Public Const DLL_VERSION_6 As Short = 6
    Public Const DLL_VERSION_7 As Short = 0
    Public Const DLL_VERSION_8 As Short = 7

    Public Const MC_NONE As Short = -1

    Public Const MC_LIMIT_POSITIVE As Short = 0
    Public Const MC_LIMIT_NEGATIVE As Short = 1
    Public Const MC_ALARM As Short = 2
    Public Const MC_HOME As Short = 3
    Public Const MC_GPI As Short = 4
    Public Const MC_ARRIVE As Short = 5
    Public Const MC_MPG As Short = 6

    Public Const MC_ENABLE As Short = 10
    Public Const MC_CLEAR As Short = 11
    Public Const MC_GPO As Short = 12

    Public Const MC_DAC As Short = 20
    Public Const MC_STEP As Short = 21
    Public Const MC_PULSE As Short = 22
    Public Const MC_ENCODER As Short = 23
    Public Const MC_ADC As Short = 24

    Public Const MC_AXIS As Short = 30
    Public Const MC_PROFILE As Short = 31
    Public Const MC_CONTROL As Short = 32

    Public Const CAPTURE_HOME As Short = 1
    Public Const CAPTURE_INDEX As Short = 2
    Public Const CAPTURE_PROBE As Short = 3
    Public Const CAPTURE_HSIO0 As Short = 6
    Public Const CAPTURE_HSIO1 As Short = 7
    Public Const CAPTURE_HOME_GPI As Short = 8

    Public Const PT_MODE_STATIC As Short = 0
    Public Const PT_MODE_DYNAMIC As Short = 1

    Public Const PT_SEGMENT_NORMAL As Short = 0
    Public Const PT_SEGMENT_EVEN As Short = 1
    Public Const PT_SEGMENT_STOP As Short = 2

    Public Const GEAR_MASTER_ENCODER As Short = 1
    Public Const GEAR_MASTER_PROFILE As Short = 2
    Public Const GEAR_MASTER_AXIS As Short = 3

    Public Const FOLLOW_MASTER_ENCODER As Short = 1
    Public Const FOLLOW_MASTER_PROFILE As Short = 2
    Public Const FOLLOW_MASTER_AXIS As Short = 3

    Public Const FOLLOW_EVENT_START As Short = 1
    Public Const FOLLOW_EVENT_PASS As Short = 2

    Public Const GEAR_EVENT_START As Short = 1
    Public Const GEAR_EVENT_PASS As Short = 2
    Public Const GEAR_EVENT_AREA As Short = 5

    Public Const FOLLOW_SEGMENT_NORMAL As Short = 0
    Public Const FOLLOW_SEGMENT_EVEN As Short = 1
    Public Const FOLLOW_SEGMENT_STOP As Short = 2
    Public Const FOLLOW_SEGMENT_CONTINUE As Short = 3

    Public Const INTERPOLATION_AXIS_MAX = 4
    Public Const CRD_FIFO_MAX = 4096
    Public Const FIFO_MAX = 2
    Public Const CRD_MAX = 2
    Public Const CRD_OPERATION_DATA_EXT_MAX = 2

    Public Const CRD_OPERATION_TYPE_NONE = 0
    Public Const CRD_OPERATION_TYPE_BUF_IO_DELAY = 1
    Public Const CRD_OPERATION_TYPE_LASER_ON = 2
    Public Const CRD_OPERATION_TYPE_LASER_OFF = 3
    Public Const CRD_OPERATION_TYPE_BUF_DA = 4
    Public Const CRD_OPERATION_TYPE_LASER_CMD = 5
    Public Const CRD_OPERATION_TYPE_LASER_FOLLOW = 6
    Public Const CRD_OPERATION_TYPE_LMTS_ON = 7
    Public Const CRD_OPERATION_TYPE_LMTS_OFF = 8
    Public Const CRD_OPERATION_TYPE_SET_STOP_IO = 9
    Public Const CRD_OPERATION_TYPE_BUF_MOVE = 10
    Public Const CRD_OPERATION_TYPE_BUF_GEAR = 11
    Public Const CRD_OPERATION_TYPE_SET_SEG_NUM = 12
    Public Const CRD_OPERATION_TYPE_STOP_MOTION = 13
    Public Const CRD_OPERATION_TYPE_SET_VAR_VALUE = 14
    Public Const CRD_OPERATION_TYPE_JUMP_NEXT_SEG = 15
    Public Const CRD_OPERATION_TYPE_SYNCH_PRF_POS = 16
    Public Const CRD_OPERATION_TYPE_VIRTUAL_TO_ACTUAL = 17
    Public Const CRD_OPERATION_TYPE_SET_USER_VAR = 18
    Public Const CRD_OPERATION_TYPE_SET_DO_BIT_PULSE = 19
    Public Const CRD_OPERATION_TYPE_BUF_COMPAREPULSE = 20
    Public Const CRD_OPERATION_TYPE_LASER_ON_EX = 21
    Public Const CRD_OPERATION_TYPE_LASER_OFF_EX = 22
    Public Const CRD_OPERATION_TYPE_LASER_CMD_EX = 23
    Public Const CRD_OPERATION_TYPE_LASER_FOLLOW_RATIO_EX = 24
    Public Const CRD_OPERATION_TYPE_LASER_FOLLOW_MODE = 25
    Public Const CRD_OPERATION_TYPE_LASER_FOLLOW_OFF = 26
    Public Const CRD_OPERATION_TYPE_LASER_FOLLOW_OFF_EX = 27
    Public Const CRD_OPERATION_TYPE_LASER_FOLLOW_SPLINE = 28
    Public Const CRD_OPERATION_TYPE_MOTION_DATA = 29

		Public Const CRD_OPERATION_TYPE_BUF_TREND = 50
		
		Public Const CRD_OPERATION_TYPE_BUF_EVENT_ON = 70
		Public Const CRD_OPERATION_TYPE_BUF_EVENT_OFF = 71

    Public Const INTERPOLATION_MOTION_TYPE_LINE = 0
    Public Const INTERPOLATION_MOTION_TYPE_CIRCLE = 1
    Public Const INTERPOLATION_MOTION_TYPE_HELIX = 2
    Public Const INTERPOLATION_MOTION_TYPE_CIRCLE_3D = 3

    Public Const INTERPOLATION_CIRCLE_PLAT_XY = 0
    Public Const INTERPOLATION_CIRCLE_PLAT_YZ = 1
    Public Const INTERPOLATION_CIRCLE_PLAT_ZX = 2

    Public Const INTERPOLATION_HELIX_CIRCLE_XY_LINE_Z = 0
    Public Const INTERPOLATION_HELIX_CIRCLE_YZ_LINE_X = 1
    Public Const INTERPOLATION_HELIX_CIRCLE_ZX_LINE_Y = 2

    Public Const INTERPOLATION_CIRCLE_DIR_CW = 0
    Public Const INTERPOLATION_CIRCLE_DIR_CCW = 1
    Public Const COMPARE_PORT_HSIO As Short = 0
    Public Const COMPARE_PORT_GPO As Short = 1

    Public Const COMPARE2D_MODE_2D As Short = 1
    Public Const COMPARE2D_MODE_1D As Short = 0

    Public Const INTERFACEBOARD20 As Short = 2
    Public Const INTERFACEBOARD30 As Short = 3

    Public Const AXIS_LASER As Short = 7
    Public Const AXIS_LASER_EX As Short = 8

    Public Const LASER_CTRL_MODE_PWM1 As Short = 0
    Public Const LASER_CTRL_FREQUENCY As Short = 1
    Public Const LASER_CTRL_VOLTAGE As Short = 2
    Public Const LASER_CTRL_MODE_PWM2 As Short = 3
    
    Public Const CRD_BUFFER_MODE_DYNAMIC_DEFAULT = 0
		Public Const CRD_BUFFER_MODE_DYNAMIC_KEEP = 1
		Public Const CRD_BUFFER_MODE_STATIC_INPUT = 11
		Public Const CRD_BUFFER_MODE_STATIC_READY = 12
		Public Const CRD_BUFFER_MODE_STATIC_START = 13
		
		Public Const CRD_SMOOTH_MODE_NONE = 0
		Public Const CRD_SMOOTH_MODE_PERCENT = 1
		Public Const CRD_SMOOTH_MODE_JERK = 2

    Public Structure TTrapPrm
        Dim acc As Double
        Dim dec As Double
        Dim velStart As Double
        Dim smoothTime As Short
    End Structure

    Public Structure TJogPrm
        Dim acc As Double
        Dim dec As Double
        Dim smooth As Double
    End Structure

    Public Structure TPid
        Dim kp As Double
        Dim ki As Double
        Dim kd As Double
        Dim kvff As Double
        Dim kaff As Double

        Dim integralLimit As Integer
        Dim derivativeLimit As Integer
        Dim limit As Short
    End Structure

    Public Structure TThreadSts
        Dim run As Short
        Dim errorValue As Short
        Dim result As Double
        Dim line As Short
    End Structure

    Public Structure TVarInfo
        Dim id As Short
        Dim dataType As Short
        Dim dumb0 As Double
        Dim dumb1 As Double
        Dim dumb2 As Double
        Dim dumb3 As Double
    End Structure
    Public Structure TCompileInfo
        Dim pFileName As String
        Dim pLineNo1 As Short
        Dim pLineNo2 As Short
        Dim pMessage As String
    End Structure

    Public Structure TCrdPrm
        Dim dimension As Short
        Dim profile1 As Short
        Dim profile2 As Short
        Dim profile3 As Short
        Dim profile4 As Short
        Dim profile5 As Short
        Dim profile6 As Short
        Dim profile7 As Short
        Dim profile8 As Short
        Dim synVelMax As Double
        Dim synAccMax As Double
        Dim evenTime As Short
        Dim setOriginFlag As Short
        Dim originPos1 As Integer
        Dim originPos2 As Integer
        Dim originPos3 As Integer
        Dim originPos4 As Integer
        Dim originPos5 As Integer
        Dim originPos6 As Integer
        Dim originPos7 As Integer
        Dim originPos8 As Integer
    End Structure

    Public Structure TCrdBufOperation
        Dim flag As Short
        Dim delay As UShort
        Dim doType As Short
        Dim doMask As UShort
        Dim doValue As UShort
        Dim dataExt1 As UShort
        Dim dataExt2 As UShort
    End Structure

    Public Structure TCrdData
        Dim motionType As Short
        Dim circlePlat As Short
        Dim pos1 As Integer
        Dim pos2 As Integer
        Dim pos3 As Integer
        Dim pos4 As Integer
        Dim pos5 As Integer
        Dim pos6 As Integer
        Dim pos7 As Integer
        Dim pos8 As Integer
        Dim radius As Double
        Dim circleDir As Short
        Dim lCenterX As Double
        Dim lCenterY As Double
        Dim lCenterZ As Double
        Dim vel As Double
        Dim acc As Double
        Dim velEndZero As Short
        Dim operation As TCrdBufOperation

        Dim cos1 As Double
        Dim cos2 As Double
        Dim cos3 As Double
        Dim cos4 As Double
        Dim cos5 As Double
        Dim cos6 As Double
        Dim cos7 As Double
        Dim cos8 As Double
        Dim velEnd As Double
        Dim velEndAdjust As Double
        Dim r As Double
    End Structure

    Public Structure TTrigger
        Dim encoder As Short
        Dim probeType As Short
        Dim probeIndex As Short
        Dim offset As Short
        Dim windowOnly As Short
        Dim firstPosition As Integer
        Dim lastPosition As Integer
    End Structure

    Public Structure TTriggerStatus
        Dim execute As Short
        Dim done As Short
        Dim position As Integer
    End Structure
    
    Public Structure TTriggerStatusEx
        Dim execute As Short
        Dim done As Short
        Dim position As Integer
        Dim clock As Integer
        Dim loopCount As Integer
    End Structure
    
    Public Structure T2DCompareData
        Dim px As Integer
        Dim py As Integer
    End Structure
    
    Public Structure T2DComparePrm
        Dim encx As Short
        Dim ency As Short
        Dim source As Short
        Dim outputType As Short
        Dim startLevel As Short
        Dim time As Short
        Dim maxerr As Short
        Dim threshold As Short
    End Structure
    
    Public Structure TCrdTime
        Dim time As Double
        Dim segmentUsed As Integer
        Dim segmentHead As Integer
        Dim segmentTail As Integer
    End Structure
    
   Public Structure TCrdSmoothInfo
        Dim enable As Short
        Dim smoothMode As Short
        Dim percent As Short
        Dim accStartPercent As Short
        Dim decEndPercent As Short
        Dim jerkMax As Double
    End Structure
    
    Public Structure TCrdSmooth
        Dim percent As Short
        Dim accStartPercent As Short
        Dim decEndPercent As Short
        Dim reserve As Double
    End Structure
    
    Public Declare Function GT_GetDllVersion Lib "gts.dll" (ByRef pDllVersion As String) As Short
    Public Declare Function GT_SetCardNo Lib "gts.dll" (ByVal index As Short) As Short
    Public Declare Function GT_GetCardNo Lib "gts.dll" (ByRef pIndex As Short) As Short

    Public Declare Function GT_GetVersion Lib "gts.dll" (ByRef pVersion As String) As Short
    Public Declare Function GT_GetInterfaceBoardSts Lib "gts.dll" (ByRef pStatus As Short) As Short
    Public Declare Function GT_SetInterfaceBoardSts Lib "gts.dll" (ByVal type As Short) As Short

    Public Declare Function GT_Open Lib "gts.dll" (Optional ByVal channel As Short = 0, Optional ByVal param As Short = 1) As Short
    Public Declare Function GT_Close Lib "gts.dll" () As Short

    Public Declare Function GT_LoadConfig Lib "gts.dll" (ByVal pFile As String) As Short

    Public Declare Function GT_AlarmOff Lib "gts.dll" (ByVal axis As Short) As Short
    Public Declare Function GT_AlarmOn Lib "gts.dll" (ByVal axis As Short) As Short
    Public Declare Function GT_LmtsOn Lib "gts.dll" (ByVal axis As Short, Optional ByVal limitType As Short = -1) As Short
    Public Declare Function GT_LmtsOff Lib "gts.dll" (ByVal axis As Short, Optional ByVal limitType As Short = -1) As Short
    Public Declare Function GT_ProfileScale Lib "gts.dll" (ByVal axis As Short, ByVal alpha As Short, ByVal beta As Short) As Short
    Public Declare Function GT_EncScale Lib "gts.dll" (ByVal axis As Short, ByVal alpha As Short, ByVal beta As Short) As Short
    Public Declare Function GT_StepDir Lib "gts.dll" (ByVal iStep As Short) As Short
    Public Declare Function GT_StepPulse Lib "gts.dll" (ByVal iStep As Short) As Short
    Public Declare Function GT_SetMtrBias Lib "gts.dll" (ByVal dac As Short, ByVal bias As Short) As Short
    Public Declare Function GT_GetMtrBias Lib "gts.dll" (ByVal dac As Short, ByRef pBias As Short) As Short
    Public Declare Function GT_SetMtrLmt Lib "gts.dll" (ByVal dac As Short, ByVal limit As Short) As Short
    Public Declare Function GT_GetMtrLmt Lib "gts.dll" (ByVal dac As Short, ByRef pLimit As Short) As Short
    Public Declare Function GT_EncSns Lib "gts.dll" (ByVal sense As UShort) As Short
    Public Declare Function GT_EncOn Lib "gts.dll" (ByVal encoder As Short) As Short
    Public Declare Function GT_EncOff Lib "gts.dll" (ByVal encoder As Short) As Short
    Public Declare Function GT_SetPosErr Lib "gts.dll" (ByVal control As Short, ByVal iError As Integer) As Short
    Public Declare Function GT_GetPosErr Lib "gts.dll" (ByVal control As Short, ByRef pError As Integer) As Short
    Public Declare Function GT_SetStopDec Lib "gts.dll" (ByVal profile As Short, ByVal decSmoothStop As Double, ByVal decAbruptStop As Double) As Short
    Public Declare Function GT_GetStopDec Lib "gts.dll" (ByVal profile As Short, ByRef pDecSmoothStop As Double, ByRef pDecAbruptStop As Double) As Short
    Public Declare Function GT_LmtSns Lib "gts.dll" (ByVal sense As UShort) As Short
    Public Declare Function GT_CtrlMode Lib "gts.dll" (ByVal axis As Short, ByVal mode As Short) As Short
    Public Declare Function GT_SetStopIo Lib "gts.dll" (ByVal axis As Short, ByVal stopType As Short, ByVal inputType As Short, ByVal inputIndex As Short) As Short
    Public Declare Function GT_GpiSns Lib "gts.dll" (ByVal sense As UShort) As Short
    Public Declare Function GT_SetAdcFilter Lib "gts.dll" (ByVal axis As Short, ByVal filterTime As Short) As Short
    Public Declare Function GT_SetAxisPrfVelFilter Lib "gts.dll" (ByVal axis As Short, ByVal filterNumExp As Short) As Short
    Public Declare Function GT_GetAxisPrfVelFilter Lib "gts.dll" (ByVal axis As Short, ByRef pFilterNumExp As Short) As Short
    Public Declare Function GT_SetAxisEncVelFilter Lib "gts.dll" (ByVal axis As Short, ByVal filterNumExp As Short) As Short
    Public Declare Function GT_GetAxisEncVelFilter Lib "gts.dll" (ByVal axis As Short, ByRef pFilterNumExp As Short) As Short
    Public Declare Function GT_SetAxisInputShaping Lib "gts.dll" (ByVal axis As Short, ByVal enable As Short, ByVal count As Short, ByVal k As Double) As Short

    Public Declare Function GT_SetDo Lib "gts.dll" (ByVal doType As Short, ByVal value As Integer) As Short
    Public Declare Function GT_SetDoBit Lib "gts.dll" (ByVal doType As Short, ByVal doIndex As Short, ByVal value As Short) As Short
    Public Declare Function GT_GetDo Lib "gts.dll" (ByVal doType As Short, ByRef pValue As Integer) As Short
    Public Declare Function GT_SetDoBitReverse Lib "gts.dll" (ByVal doType As Short, ByVal doIndex As Short, ByVal value As Short, ByVal reverseTime As Short) As Short
    Public Declare Function GT_SetDoMask Lib "gts.dll" (ByVal doType As Short, ByVal doMask As UShort, ByVal value As Integer) As Short
    Public Declare Function GT_EnableDoBitPulse Lib "gts.dll" (ByVal doType As Short, ByVal doIndex As Short, ByVal highLevelTime As UShort, ByVal lowLevelTime As UShort, ByVal pulseNum As Integer, ByVal firstLevel As Short) As Short
    Public Declare Function GT_DisableDoBitPulse Lib "gts.dll" (ByVal doType As Short, ByVal doIndex As Short) As Short

    Public Declare Function GT_GetDi Lib "gts.dll" (ByVal diType As Short, ByRef pValue As Integer) As Short
    Public Declare Function GT_GetDiReverseCount Lib "gts.dll" (ByVal diType As Short, ByVal diIndex As Short, ByRef pReverseCount As UInteger, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_SetDiReverseCount Lib "gts.dll" (ByVal diType As Short, ByVal diIndex As Short, ByRef pReverseCount As UInteger, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_GetDiRaw Lib "gts.dll" (ByVal diType As Short, ByRef pValue As Integer) As Short

    Public Declare Function GT_SetDac Lib "gts.dll" (ByVal dac As Short, ByRef pValue As Short, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_GetDac Lib "gts.dll" (ByVal dac As Short, ByRef pValue As Short, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short

    Public Declare Function GT_GetAdc Lib "gts.dll" (ByVal adc As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAdcValue Lib "gts.dll" (ByVal adc As Short, ByRef pValue As Short, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short

    Public Declare Function GT_SetEncPos Lib "gts.dll" (ByVal encoder As Short, ByVal encPos As Integer) As Short
    Public Declare Function GT_GetEncPos Lib "gts.dll" (ByVal encoder As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetEncPosPre Lib "gts.dll" (ByVal encoder As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetEncVel Lib "gts.dll" (ByVal encoder As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short

    Public Declare Function GT_SetCaptureMode Lib "gts.dll" (ByVal encoder As Short, ByVal mode As Short) As Short
    Public Declare Function GT_GetCaptureMode Lib "gts.dll" (ByVal encoder As Short, ByRef pMode As Short, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_StopCapture Lib "gts.dll" (ByVal encoder As Short) As Short
    Public Declare Function GT_GetCaptureStatus Lib "gts.dll" (ByVal encoder As Short, ByRef pStatus As Short, ByRef pValue As Integer, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_SetCaptureSense Lib "gts.dll" (ByVal encoder As Short, ByVal mode As Short, ByVal sense As Short) As Short
    Public Declare Function GT_ClearCaptureStatus Lib "gts.dll" (ByVal encoder As Short) As Short
    Public Declare Function GT_SetCaptureRepeat Lib "gts.dll" (ByVal encoder As Short, ByVal count As Short) As Short
    Public Declare Function GT_GetCaptureRepeatStatus Lib "gts.dll" (ByVal encoder As Short, ByRef pCount As Short) As Short
    Public Declare Function GT_GetCaptureRepeatPos Lib "gts.dll" (ByVal encoder As Short, ByRef pValue As Integer, ByVal startNum As Short, ByVal count As Short) As Short

    Public Declare Function GT_SetCaptureEncoder Lib "gts.dll" (ByVal trigger As Short, ByVal encoder As Short) As Short
    Public Declare Function GT_GetCaptureWidth Lib "gts.dll" (ByVal trigger As Short, ByRef pWidth As Short, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_GetCaptureHomeGpi Lib "gts.dll" (ByVal trigger As Short, ByRef pHomeSts As Short, ByRef pHomePos As Short, ByRef pGpiSts As Short, ByRef pGpiPos As Short, Optional ByVal count As Short = 1) As Short

    Public Declare Function GT_Reset Lib "gts.dll" () As Short
    Public Declare Function GT_GetClock Lib "gts.dll" (ByRef pClock As UInteger, Optional ByRef pLoop As UInteger = Nothing) As Short
    Public Declare Function GT_GetClockHighPrecision Lib "gts.dll" (ByRef pClock As UInteger) As Short

    Public Declare Function GT_GetSts Lib "gts.dll" (ByVal axis As Short, ByRef pSts As Integer, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_ClrSts Lib "gts.dll" (ByVal axis As Short, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_AxisOn Lib "gts.dll" (ByVal axis As Short) As Short
    Public Declare Function GT_AxisOff Lib "gts.dll" (ByVal axis As Short) As Short
    Public Declare Function GT_Stop Lib "gts.dll" (ByVal mask As Integer, ByVal stopOption As Integer) As Short
    Public Declare Function GT_SetPrfPos Lib "gts.dll" (ByVal profile As Short, ByVal prfPos As Integer) As Short
    Public Declare Function GT_SynchAxisPos Lib "gts.dll" (ByVal mask As Integer) As Short
    Public Declare Function GT_ZeroPos Lib "gts.dll" (ByVal axis As Short, Optional ByVal count As Short = 1) As Short

    Public Declare Function GT_SetSoftLimit Lib "gts.dll" (ByVal axis As Short, ByVal positive As Integer, ByVal negative As Integer) As Short
    Public Declare Function GT_GetSoftLimit Lib "gts.dll" (ByVal axis As Short, ByRef positive As Integer, ByRef pNegative As Integer) As Short
    Public Declare Function GT_SetAxisBand Lib "gts.dll" (ByVal axis As Short, ByVal band As Integer, ByVal time As Integer) As Short
    Public Declare Function GT_GetAxisBand Lib "gts.dll" (ByVal axis As Short, ByRef pBand As Integer, ByRef pTime As Integer) As Short
    Public Declare Function GT_SetBacklash Lib "gts.dll" (ByVal axis As Short, ByVal compValue As Integer, ByVal compChangeValue As Double, ByVal compDir As Integer) As Short
    Public Declare Function GT_GetBacklash Lib "gts.dll" (ByVal axis As Short, ByRef pCompValue As Integer, ByRef pCompChangeValue As Double, ByRef pCompDir As Integer) As Short
    Public Declare Function GT_SetLeadScrewComp Lib "gts.dll" (ByVal axis As Short, ByVal n As Short, ByVal startPos As Integer, ByVal lenPos As Integer, ByRef pCompPos As Integer, ByRef pCompNeg As Integer) As Short
    Public Declare Function GT_EnableLeadScrewComp Lib "gts.dll" (ByVal axis As Short, ByVal mode As Short) As Short
    Public Declare Function GT_GetCompensate Lib "gts.dll" (ByVal axis As Short, ByRef pPitchError As Double, ByRef pCrossError As Double, ByRef pBacklashError As Double, ByRef pEncPos As Double, ByRef pPrfPos As Double) As Short

    Public Declare Function GT_EnableGantry Lib "gts.dll" (ByVal gantryMaster As Short, ByVal gantrySlave As Short, ByVal masterKp As Double, ByVal slaveKp As Double) As Short
    Public Declare Function GT_DisableGantry Lib "gts.dll" () As Short
    Public Declare Function GT_SetGantryErrLmt Lib "gts.dll" (ByVal gantryErrLmt As Integer) As Short
    Public Declare Function GT_GetGantryErrLmt Lib "gts.dll" (ByRef pGantryErrLmt As Integer) As Short
    Public Declare Function GT_ZeroGantryPos Lib "gts.dll" (ByVal gantryMaster As Short,ByVal gantrySlave As Short) As Short

    Public Declare Function GT_GetPrfPos Lib "gts.dll" (ByVal profile As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetPrfVel Lib "gts.dll" (ByVal profile As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetPrfAcc Lib "gts.dll" (ByVal profile As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetPrfMode Lib "gts.dll" (ByVal profile As Short, ByRef pValue As Integer, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short

    Public Declare Function GT_GetAxisPrfPos Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAxisPrfVel Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAxisPrfAcc Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAxisEncPos Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAxisEncVel Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAxisEncAcc Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short
    Public Declare Function GT_GetAxisError Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double, Optional ByVal count As Short = 1, Optional ByRef pClock As UInteger = Nothing) As Short

    Public Declare Function GT_SetLongVar Lib "gts.dll" (ByVal index As Short, ByVal value As Integer) As Short
    Public Declare Function GT_GetLongVar Lib "gts.dll" (ByVal index As Short, ByRef pValue As Integer) As Short
    Public Declare Function GT_SetDoubleVar Lib "gts.dll" (ByVal index As Short, ByVal value As Double) As Short
    Public Declare Function GT_GetDoubleVar Lib "gts.dll" (ByVal index As Short, ByRef pValue As Double) As Short

    Public Declare Function GT_SetControlFilter Lib "gts.dll" (ByVal control As Short, ByVal index As Short) As Short
    Public Declare Function GT_GetControlFilter Lib "gts.dll" (ByVal control As Short, ByRef pIndex As Short) As Short

    Public Declare Function GT_SetPid Lib "gts.dll" (ByVal control As Short, ByVal index As Short, ByRef pPid As TPid) As Short
    Public Declare Function GT_GetPid Lib "gts.dll" (ByVal control As Short, ByVal index As Short, ByRef pPid As TPid) As Short

    Public Declare Function GT_SetKvffFilter Lib "gts.dll" (ByVal control As Short, ByVal index As Short, ByVal kvffFilterExp As Short, ByVal accMax As Double) As Short
    Public Declare Function GT_GetKvffFilter Lib "gts.dll" (ByVal control As Short, ByVal index As Short, ByRef pKvffFilterExp As Short, ByRef pAccMax As Double) As Short

    Public Declare Function GT_Update Lib "gts.dll" (ByVal mask As Integer) As Short
    Public Declare Function GT_SetPos Lib "gts.dll" (ByVal profile As Short, ByVal pos As Integer) As Short
    Public Declare Function GT_GetPos Lib "gts.dll" (ByVal profile As Short, ByRef pPos As Integer) As Short
    Public Declare Function GT_SetVel Lib "gts.dll" (ByVal profile As Short, ByVal vel As Double) As Short
    Public Declare Function GT_GetVel Lib "gts.dll" (ByVal profile As Short, ByRef pVel As Double) As Short

    Public Declare Function GT_PrfTrap Lib "gts.dll" (ByVal profile As Short) As Short
    Public Declare Function GT_SetTrapPrm Lib "gts.dll" (ByVal profile As Short, ByRef pPrm As TTrapPrm) As Short
    Public Declare Function GT_GetTrapPrm Lib "gts.dll" (ByVal profile As Short, ByRef pPrm As TTrapPrm) As Short

    Public Declare Function GT_PrfJog Lib "gts.dll" (ByVal profile As Short) As Short
    Public Declare Function GT_SetJogPrm Lib "gts.dll" (ByVal profile As Short, ByRef pPrm As TJogPrm) As Short
    Public Declare Function GT_GetJogPrm Lib "gts.dll" (ByVal profile As Short, ByRef pPrm As TJogPrm) As Short

    Public Declare Function GT_PrfPt Lib "gts.dll" (ByVal profile As Short, Optional ByVal mode As Short = PT_MODE_STATIC) As Short
    Public Declare Function GT_SetPtLoop Lib "gts.dll" (ByVal profile As Short, ByVal ptLoop As Integer) As Short
    Public Declare Function GT_GetPtLoop Lib "gts.dll" (ByVal profile As Short, ByRef pLoop As Integer) As Short
    Public Declare Function GT_PtSpace Lib "gts.dll" (ByVal profile As Short, ByRef pSpace As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_PtData Lib "gts.dll" (ByVal profile As Short, ByVal pos As Double, ByVal time As Integer, Optional ByVal ptType As Short = PT_SEGMENT_NORMAL, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_PtDataWN Lib "gts.dll" (ByVal profile As Short, ByVal pos As Double, ByVal time As Integer, Optional ByVal ptType As Short = PT_SEGMENT_NORMAL, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_PtClear Lib "gts.dll" (ByVal profile As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_PtStart Lib "gts.dll" (ByVal mask As Integer, Optional ByVal fifoOption As Integer = 0) As Short
    Public Declare Function GT_SetPtMemory Lib "gts.dll" (ByVal profile As Short, ByVal memory As Short) As Short
    Public Declare Function GT_GetPtMemory Lib "gts.dll" (ByVal profile As Short, ByRef pMemory As Short) As Short
    Public Declare Function GT_PtGetSegNum Lib "gts.dll" (ByVal profile As Short, ByRef pSegNum As Integer) As Short
    Public Declare Function GT_SetPtPrecisionMode Lib "gts.dll" (ByVal profile As Short, ByVal precisionMode As Short ) As Short
    Public Declare Function GT_GetPtPrecisionMode Lib "gts.dll" (ByVal profile As Short, ByRef pPrecisionMode As Short) As Short
    Public Declare Function GT_SetPtVel Lib "gts.dll" (ByVal profile As Short, ByVal velLast As Double, ByVal fifo As Short) As Short
    Public Declare Function GT_SetPtLink Lib "gts.dll" (ByVal profile As Short, ByVal fifo As Short, ByVal list As Short) As Short
    Public Declare Function GT_GetPtLink Lib "gts.dll" (ByVal profile As Short, ByVal fifo As Short, ByRef pList As Short) As Short
    Public Declare Function GT_PtDoBit Lib "gts.dll" (ByVal profile As Short, ByVal doType As Short, ByVal doType As Short, ByVal index As Short, ByVal value As Short, ByVal fifo As Short) As Short
    Public Declare Function GT_PtAo Lib "gts.dll" (ByVal profile As Short, ByVal aoType As Short, ByVal index As Short, ByVal value As Short, ByVal fifo As Short) As Short

    Public Declare Function GT_PrfGear Lib "gts.dll" (ByVal profile As Short, Optional ByVal dir As Short = 0) As Short
    Public Declare Function GT_SetGearMaster Lib "gts.dll" (ByVal profile As Short, ByVal masterIndex As Short, Optional ByVal masterType As Short = GEAR_MASTER_PROFILE, Optional ByVal masterItem As Short = 0) As Short
    Public Declare Function GT_GetGearMaster Lib "gts.dll" (ByVal profile As Short, ByRef pMasterIndex As Short, Optional ByRef pMasterType As Short = Nothing, Optional ByRef pMasterItem As Short = Nothing) As Short
    Public Declare Function GT_SetGearRatio Lib "gts.dll" (ByVal profile As Short, ByVal masterEven As Integer, ByVal slaveEven As Integer, Optional ByVal masterSlope As Integer = 0) As Short
    Public Declare Function GT_GetGearRatio Lib "gts.dll" (ByVal profile As Short, ByRef pMasterEven As Integer, ByRef pSlaveEven As Integer, Optional ByRef pMasterSlope As Integer = Nothing) As Short
    Public Declare Function GT_GearStart Lib "gts.dll" (ByVal mask As Integer) As Short
    Public Declare Function GT_SetGearEvent Lib "gts.dll" (ByVal profile As Short, ByVal gearEvent As Short, ByVal startPara0 As Integer, ByVal startPara1 As Integer) As Short
    Public Declare Function GT_GetGearEvent Lib "gts.dll" (ByVal profile As Short, ByRef pGearEvent As Short, ByRef startPara0 As Integer, ByRef startPara1 As Integer) As Short

    Public Declare Function GT_PrfFollow Lib "gts.dll" (ByVal profile As Short, Optional ByVal dir As Short = 0) As Short
    Public Declare Function GT_SetFollowMaster Lib "gts.dll" (ByVal profile As Short, ByVal masterIndex As Short, Optional ByVal masterType As Short = FOLLOW_MASTER_PROFILE, Optional ByVal masterItem As Short = 0) As Short
    Public Declare Function GT_GetFollowMaster Lib "gts.dll" (ByVal profile As Short, ByRef pMasterIndex As Short, Optional ByRef pMasterType As Short = Nothing, Optional ByRef pMasterItem As Short = Nothing) As Short
    Public Declare Function GT_SetFollowLoop Lib "gts.dll" (ByVal profile As Short, ByVal followLoop As Integer) As Short
    Public Declare Function GT_GetFollowLoop Lib "gts.dll" (ByVal profile As Short, ByRef pLoop As Integer) As Short
    Public Declare Function GT_SetFollowEvent Lib "gts.dll" (ByVal profile As Short, ByVal followEvent As Short, ByVal masterDir As Short, Optional ByVal pos As Integer = 0) As Short
    Public Declare Function GT_GetFollowEvent Lib "gts.dll" (ByVal profile As Short, ByRef pEvent As Short, ByRef pMasterDir As Short, Optional ByRef pPos As Integer = Nothing) As Short
    Public Declare Function GT_FollowSpace Lib "gts.dll" (ByVal profile As Short, ByRef pSpace As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_FollowData Lib "gts.dll" (ByVal profile As Short, ByVal masterSegment As Integer, ByVal slaveSegment As Double, Optional ByVal followType As Short = FOLLOW_SEGMENT_NORMAL, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_FollowClear Lib "gts.dll" (ByVal profile As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_FollowStart Lib "gts.dll" (ByVal mask As Integer, Optional ByVal fifoOption As Integer = 0) As Short
    Public Declare Function GT_FollowSwitch Lib "gts.dll" (ByVal mask As Integer) As Short
    Public Declare Function GT_SetFollowMemory Lib "gts.dll" (ByVal profile As Short, ByVal memory As Short) As Short
    Public Declare Function GT_GetFollowMemory Lib "gts.dll" (ByVal profile As Short, ByRef pMemory As Short) As Short
    Public Declare Function GT_GetFollowStatus Lib "gts.dll" (ByVal profile As Short, ByRef pFifoNum As Short, ByRef pSwitchStatus As Short) As Short
    Public Declare Function GT_SetFollowPhasing Lib "gts.dll" (ByVal profile As Short, ByVal profilePhasing As Short) As Short
    Public Declare Function GT_GetFollowPhasing Lib "gts.dll" (ByVal profile As Short, ByRef pProfilePhasing As Short) As Short

    Public Declare Function GT_Compile Lib "gts.dll" (ByVal pFileName As String, ByRef pWrongInfo As TCompileInfo) As Short
    Public Declare Function GT_Download Lib "gts.dll" (ByVal pFileName As String) As Short

    Public Declare Function GT_GetFunId Lib "gts.dll" (ByVal pFunName As String, ByRef pFunId As Short) As Short
    Public Declare Function GT_Bind Lib "gts.dll" (ByVal thread As Short, ByVal funId As Short, ByVal page As Short) As Short

    Public Declare Function GT_RunThread Lib "gts.dll" (ByVal thread As Short) As Short
    Public Declare Function GT_StopThread Lib "gts.dll" (ByVal thread As Short) As Short
    Public Declare Function GT_PauseThread Lib "gts.dll" (ByVal thread As Short) As Short

    Public Declare Function GT_GetThreadSts Lib "gts.dll" (ByVal thread As Short, ByRef pThreadSts As TThreadSts) As Short

    Public Declare Function GT_GetVarId Lib "gts.dll" (ByVal pFunName As String, ByVal pVarName As String, ByRef pVarInfo As TVarInfo) As Short
    Public Declare Function GT_SetVarValue Lib "gts.dll" (ByVal page As Short, ByRef pVarInfo As TVarInfo, ByRef pValue As Double, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_GetVarValue Lib "gts.dll" (ByVal page As Short, ByRef pVarInfo As TVarInfo, ByRef pValue As Double, Optional ByVal count As Short = 1) As Short

		Public Declare Function GT_SetCrdMapBase Lib "gts.dll" (ByVal crd As Short, ByVal base As Short) As Short
		Public Declare Function GT_GetCrdMapBase Lib "gts.dll" (ByVal crd As Short, ByRef pBase As Short) As Short
		Public Declare Function GT_SetCrdSmooth Lib "gts.dll" (ByVal crd As Short, ByRef pCrdSmooth As TCrdSmooth) As Short
		Public Declare Function GT_GetCrdSmooth Lib "gts.dll" (ByVal crd As Short, ByRef pCrdSmooth As TCrdSmooth) As Short
		Public Declare Function GT_SetCrdJerk Lib "gts.dll" (ByVal crd As Short, ByVal jerkMax As Double) As Short
		Public Declare Function GT_GetCrdJerk Lib "gts.dll" (ByVal crd As Short, ByRef pJerkMax As Double) As Short
    Public Declare Function GT_SetCrdPrm Lib "gts.dll" (ByVal crd As Short, ByRef pCrdPrm As TCrdPrm) As Short
    Public Declare Function GT_GetCrdPrm Lib "gts.dll" (ByVal crd As Short, ByRef pCrdPrm As TCrdPrm) As Short
    Public Declare Function GT_SetArcAllowError Lib "gts.dll" (ByVal crd As Short, ByVal error1 As Double) As Short
    Public Declare Function GT_CrdSpace Lib "gts.dll" (ByVal crd As Short, ByRef pSpace As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_CrdData Lib "gts.dll" (ByVal crd As Short, ByVal pCrdData As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_CrdDataCircle Lib "gts.dll" (ByVal crd As Short, ByRef pCrdData As TCrdData, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXY Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZ Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZA Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYG0 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZG0 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAG0 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYR Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal radius As Double, ByVal circleDir As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYC Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal circleDir As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZR Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal circleDir As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZC Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal circleDir As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXR Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal radius As Double, ByVal circleDir As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXC Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal circleDir As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYZ Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal interX As Double, ByVal interY As Double, ByVal interZ As Double, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short

    Public Declare Function GT_LnXYOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYG0Override2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZG0Override2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAG0Override2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYROverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYCOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZROverride2 Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0)
    Public Declare Function GT_ArcYZCOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXROverride2 Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0)
    Public Declare Function GT_ArcZXCOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYRZ Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYCZ Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZRX Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0)
    Public Declare Function GT_HelixYZCX Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXRY Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXCY Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYRZOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYCZOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZRXOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZCXOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXRYOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXCYOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYG0WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZG0WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAG0WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYRWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYCWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZRWN Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZCWN Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXRWN Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXCWN Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYZWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal interX As Double, ByVal interY As Double, ByVal interZ As Double, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYG0Override2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZG0Override2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_LnXYZAG0Override2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal a As Integer, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYROverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcXYCOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZROverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcYZCOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXROverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_ArcZXCOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal z As Integer, ByVal x As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYRZWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYCZWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZRXWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZCXWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXRYWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXCYWN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYRZOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixXYCZOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal xCenter As Double, ByVal yCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZRXOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixYZCXOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal yCenter As Double, ByVal zCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXRYOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal radius As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_HelixZXCYOverride2WN Lib "gts.dll" (ByVal crd As Short, ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal zCenter As Double, ByVal xCenter As Double, ByVal radius As Short, ByVal synVel As Double, ByVal synAcc As Double, Optional ByVal velEnd As Double = 0, Optional ByVal segNum As Integer = 0, Optional ByVal fifo As Short = 0) As Short

		Public Declare Function GT_BufTrend Lib "gts.dll" (ByVal crd As Short, ByVal trendSegNum As Integer, ByVal trendDistance As Double, ByVal trendVelEnd As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufIO Lib "gts.dll" (ByVal crd As Short, ByVal doType As UShort, ByVal doMask As UShort, ByVal doValue As UShort, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufEnableDoBitPulse Lib "gts.dll" (ByVal crd As Short, ByVal doType As Short, ByVal doIndex As Short, ByVal highLevelTime As UShort, ByVal lowLevelTime As UShort, ByVal pulseNum As Integer, ByVal firstLevel As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufDisableDoBitPulse Lib "gts.dll" (ByVal crd As Short, ByVal doType As Short, ByVal doIndex As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufDelay  Lib "gts.dll" (ByVal crd As Short, ByVal delayTime As UShort, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufDA Lib "gts.dll" (ByVal crd As Short, ByVal chn As Short, ByVal daValue As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufLmtsOn Lib "gts.dll" (ByVal crd As Short, ByVal axis As Short, ByVal limitType As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufLmtsOff Lib "gts.dll" (ByVal crd As Short, ByVal axis As Short, ByVal limitType As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufSetStopIo Lib "gts.dll" (ByVal crd As Short, ByVal axis As Short, ByVal stopType As Short, ByVal inputType As Short, ByVal inputIndex As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufMove Lib "gts.dll" (ByVal crd As Short, ByVal moveAxis As Short, ByVal pos As Integer, ByVal vel As Double, ByVal acc As Double, ByVal modal As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufGear Lib "gts.dll" (ByVal crd As Short, ByVal gearAxis As Short, ByVal pos As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufGearPercent Lib "gts.dll" (ByVal crd As Short, ByVal gearAxis As Short, ByVal pos As Integer, ByVal accPercent As Short, ByVal decPercent As Short, Optional ByVal fifo As Short = 0)
    Public Declare Function GT_BufStopMotion Lib "gts.dll" (ByVal crd As Short, Optional ByVal fifo As Short = 0)
    Public Declare Function GT_BufSetVarValue Lib "gts.dll" (ByVal crd As Short, ByVal pageId As Short, ByRef pVarInfo As TVarInfo, ByVal value As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufJumpNextSeg Lib "gts.dll" (ByVal crd As Short, ByVal axis As Short, ByVal limitType As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufSynchPrfPos Lib "gts.dll" (ByVal crd As Short, ByVal encoder As Short, ByVal profile As Short, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufVirtualToActual Lib "gts.dll" (ByVal crd As Short, Optional ByVal fifo As Short = 0)
    Public Declare Function GT_BufSetLongVar Lib "gts.dll" (ByVal crd As Short, ByVal index As Short, ByVal value As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_BufSetDoubleVar Lib "gts.dll" (ByVal crd As Short, ByVal index As Short, ByVal value As Double, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_CrdStart Lib "gts.dll" (ByVal mask As Short, ByVal optionV As Short) As Short
    Public Declare Function GT_CrdStartStep Lib "gts.dll" (ByVal mask As Short, ByVal stepOption As Short) As Short
    Public Declare Function GT_CrdStepMode Lib "gts.dll" (ByVal mask As Short, ByVal modeOption As Short) As Short
    Public Declare Function GT_SetOverride Lib "gts.dll" (ByVal crd As Short, ByVal synVelRatio As Double) As Short
    Public Declare Function GT_SetOverride2 Lib "gts.dll" (ByVal crd As Short, ByVal synVelRatio As Double) As Short
    Public Declare Function GT_InitLookAhead Lib "gts.dll" (ByVal crd As Short, ByVal fifo As Short, ByVal T As Double, ByVal accMax As Double, ByVal n As Short, ByRef pLookAheadBuf As TCrdData) As Short
    Public Declare Function GT_GetLookAheadSpace Lib "gts.dll" (ByVal crd As Short, ByVal pSpace As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_GetLookAheadSegCount Lib "gts.dll" (ByVal crd As Short, ByVal pSegCount As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_CrdClear Lib "gts.dll" (ByVal crd As Short, ByVal fifo As Short) As Short
    Public Declare Function GT_CrdStatus Lib "gts.dll" (ByVal crd As Short, ByRef pRun As Short, ByRef pSegment As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_SetUserSegNum Lib "gts.dll" (ByVal crd As Short, ByVal segNum As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_GetUserSegNum Lib "gts.dll" (ByVal crd As Short, ByRef pSegment As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_GetUserSegNumWN Lib "gts.dll" (ByVal crd As Short, ByVal pSegment As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_GetRemainderSegNum Lib "gts.dll" (ByVal crd As Short, ByRef pSegment As Integer, Optional ByVal fifo As Short = 0) As Short
    Public Declare Function GT_SetCrdStopDec Lib "gts.dll" (ByVal crd As Short, ByVal decSmoothStop As Double, ByVal decAbruptStop As Double) As Short
    Public Declare Function GT_GetCrdStopDec Lib "gts.dll" (ByVal crd As Short, ByRef pDecSmoothStop As Double, ByRef pDecAbruptStop As Double) As Short
    Public Declare Function GT_SetCrdLmtStopMode Lib "gts.dll" (ByVal crd As Short, ByVal lmtStopMode As Short) As Short
    Public Declare Function GT_GetCrdLmtStopMode Lib "gts.dll" (ByVal crd As Short, ByRef pLmtStopMode As Short) As Short
    Public Declare Function GT_GetUserTargetVel Lib "gts.dll" (ByVal crd As Short, ByRef pTargetVel As Double) As Short
    Public Declare Function GT_GetSegTargetPos Lib "gts.dll" (ByVal crd As Short, ByRef pTargetPos As Integer) As Short
    Public Declare Function GT_GetCrdPos Lib "gts.dll" (ByVal crd As Short, ByRef pPos As Double) As Short
    Public Declare Function GT_GetCrdVel Lib "gts.dll" (ByVal crd As Short, ByRef pSynVel As Double) As Short
    Public Declare Function GT_SetCrdSingleMaxVel Lib "gts.dll" (ByVal crd As Short, ByRef pMaxVel As Double) As Short
    Public Declare Function GT_GetCrdSingleMaxVel Lib "gts.dll" (ByVal crd As Short, ByRef pMaxVel As Double) As Short
    Public Declare Function GT_GetCmdCount Lib "gts.dll" (ByVal crd As Short, ByRef pResult As Short, ByVal fifo As Short) As Short
    Public Declare Function GT_BufLaserOn Lib "gts.dll" (ByVal crd As Short, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_BufLaserOff Lib "gts.dll" (ByVal crd As Short, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_BufLaserPrfCmd Lib "gts.dll" (ByVal crd As Short, ByVal laserPower As Double, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_BufLaserFollowRatio Lib "gts.dll" (ByVal crd As Short, ByVal ratio As Double, ByVal minPower As Double, ByVal maxPower As Double, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_BufLaserFollowMode Lib "gts.dll" (ByVal crd As Short, Optional ByVal source As Short = 0, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0, Optional ByVal startPower As Double = 0) As Short
    Public Declare Function GT_BufLaserFollowOff Lib "gts.dll" (ByVal crd As Short, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_BufLaserFollowSpline Lib "gts.dll" (ByVal crd As Short, ByVal tableId As Short, ByVal minPower As Double, ByVal maxPower As Double, Optional ByVal fifo As Short = 0, Optional ByVal channel As Short = 0) As Short

    Public Declare Function GT_PrfPvt Lib "gts.dll" (ByVal profile As Short) As Short
    Public Declare Function GT_SetPvtLoop Lib "gts.dll" (ByVal profile As Short, ByVal loopValue As Integer) As Short
    Public Declare Function GT_GetPvtLoop Lib "gts.dll" (ByVal profile As Short, ByRef pLoopCount As Integer, ByRef pLoop As Integer) As Short
    Public Declare Function GT_PvtStatus Lib "gts.dll" (ByVal profile As Short, ByRef pTableId As Short, ByRef pTime As Double, Optional ByVal Count As Short = 1) As Short
    Public Declare Function GT_PvtStart Lib "gts.dll" (ByVal mask As Integer) As Short
    Public Declare Function GT_PvtTableSelect Lib "gts.dll" (ByVal profile As Short, ByVal tableId As Short) As Short

    Public Declare Function GT_PvtTable Lib "gts.dll" (ByVal tableId As Short, ByVal count As Integer, ByRef pTime As Double, ByRef pPos As Double, ByRef pVel As Double) As Short
    Public Declare Function GT_PvtTableEx Lib "gts.dll" (ByVal tableId As Short, ByVal count As Integer, ByRef pTime As Double, ByRef pPos As Double, ByRef pVelBegin As Double, ByRef pVelEnd As Double) As Short
    Public Declare Function GT_PvtTableComplete Lib "gts.dll" (ByVal tableId As Short, ByVal count As Integer, ByRef pTime As Double, ByRef pPos As Double, ByRef pA As Double, ByRef pB As Double, ByRef pC As Double, Optional ByVal velBegin As Double = 0, Optional ByVal velEnd As Double = 0) As Short
    Public Declare Function GT_PvtTablePercent Lib "gts.dll" (ByVal tableId As Short, ByVal count As Integer, ByRef pTime As Double, ByRef pPos As Double, ByRef pPercent As Double, Optional ByVal velBegin As Double = 0) As Short
    Public Declare Function GT_PvtPercentCalculate Lib "gts.dll" (ByVal n As Integer, ByRef pTime As Double, ByRef pPos As Double, ByRef pPercent As Double, ByVal velBegin As Double, ByRef pVel As Double) As Short
    Public Declare Function GT_PvtTableContinuous Lib "gts.dll" (ByVal tableId As Short, ByVal count As Integer, ByRef pPos As Double, ByRef pVel As Double, ByRef pPercent As Double, ByRef pVelMax As Double, ByRef pAcc As Double, ByRef pDec As Double, ByVal timeBegin As Double) As Short
    Public Declare Function GT_PvtContinuousCalculate Lib "gts.dll" (ByVal n As Integer, ByRef pPos As Double, ByRef pVel As Double, ByRef pPercent As Double, ByRef pVelMax As Double, ByRef pAcc As Double, ByRef pDec As Double, ByRef pTime As Double) As Short
    Public Declare Function GT_PvtTableMovePercent Lib "gts.dll" (ByVal tableId As Short, ByVal distance As Integer, ByVal vm As Double, ByVal acc As Double, ByVal pa1 As Double, ByVal pa2 As Double, ByVal dec As Double, ByVal pd1 As Double, ByVal pd2 As Double, ByRef pVel As Double, ByRef pAcc As Double, ByRef pDec As Double, ByRef pTime As Double) As Short
    Public Declare Function GT_PvtTableMovePercentEx Lib "gts.dll" (ByVal tableId As Short, ByVal distance As Integer, ByVal vm As Double, ByVal acc As Double, ByVal pa1 As Double, ByVal pa2 As Double, ByVal ma As Double, ByVal dec As Double, ByVal pd1 As Double, ByVal pd2 As Double, ByVal md As Double, ByRef pVel As Double, ByRef pAcc As Double, ByRef pDec As Double, ByRef pTime As Double) As Short

    Public Declare Function GT_HomeInit Lib "gts.dll" () As Short
    Public Declare Function GT_Home Lib "gts.dll" (ByVal axis As Short, ByVal pos As Integer, ByVal vel As Double, ByVal acc As Double, ByVal offset As Integer) As Short
    Public Declare Function GT_Index Lib "gts.dll" (ByVal axis As Short, ByVal pos As Integer, ByVal offset As Integer) As Short
    Public Declare Function GT_HomeStop Lib "gts.dll" (ByVal axis As Short, ByVal pos As Integer, ByVal vel As Double, ByVal acc As Double) As Short
    Public Declare Function GT_HomeSts Lib "gts.dll" (ByVal axis As Short, ByRef pStatus As UShort) As Short

    Public Declare Function GT_HandwheelInit Lib "gts.dll" () As Short
    Public Declare Function GT_SetHandwheelStopDec Lib "gts.dll" (ByVal slave As Short, ByVal decSmoothStop As Double, ByVal decAbruptStop As Double) As Short
    Public Declare Function GT_StartHandwheel Lib "gts.dll" (ByVal slave As Short, ByVal master As Short, ByVal masterEven As Short, ByVal slaveEven As Short, ByVal intervalTime As Short, ByVal acc As Double, ByVal dec As Double, ByVal vel As Double, ByVal stopWaitTime As Short) As Short
    Public Declare Function GT_EndHandwheel Lib "gts.dll" (ByVal slave As Short) As Short

    Public Declare Function GT_SetTrigger Lib "gts.dll" (ByVal i As Short, ByRef pTrigger As TTrigger) As Short
    Public Declare Function GT_GetTrigger Lib "gts.dll" (ByVal i As Short, ByRef pTrigger As TTrigger) As Short
    Public Declare Function GT_GetTriggerStatus Lib "gts.dll" (ByVal i As Short, ByRef pTriggerStatus As TTriggerStatus, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_GetTriggerStatusEx Lib "gts.dll" (ByVal i As Short, ByRef pTriggerStatusEx As TTriggerStatusEx, Optional ByVal count As Short = 1) As Short
    Public Declare Function GT_ClearTriggerStatus Lib "gts.dll" (ByVal i As Short) As Short

    Public Declare Function GT_SetComparePort Lib "gts.dll" (ByVal channel As Short, ByVal hsio0 As Short, ByVal hsio1 As Short) As Short

    Public Declare Function GT_ComparePulse Lib "gts.dll" (ByVal level As Short, ByVal outputType As Short, ByVal time As Short) As Short
    Public Declare Function GT_CompareStop Lib "gts.dll" () As Short
    Public Declare Function GT_CompareStatus Lib "gts.dll" (ByRef pStatus As Short, ByRef pCount As Integer) As Short
    Public Declare Function GT_CompareData Lib "gts.dll" (ByVal encoder As Short, ByVal source As Short, ByVal pulseType As Short, ByVal startLevel As Short, ByVal time As Short, ByVal pBuf1() As Integer, ByVal count1 As Short, ByVal pBuf2() As Integer, ByVal count2 As Short) As Short
    Public Declare Function GT_CompareLinear Lib "gts.dll" (ByVal encoder As Short, ByVal channel As Short, ByVal startPos As Integer, ByVal repeatTimes As Integer, ByVal interval As Integer, ByVal time As Short, ByVal source As Short) As Short
    Public Declare Function GT_CompareContinuePulseMode Lib "gts.dll" (ByVal mode As Short, ByVal count As Short, ByVal standTime As Short) As Short

    Public Declare Function GT_SetEncResponseCheck Lib "gts.dll" (ByVal control As Short, ByVal dacThreshold As Short, ByVal minEncVel As Double, ByVal time As Integer) As Short
    Public Declare Function GT_GetEncResponseCheck Lib "gts.dll" (ByVal control As Short, ByRef pDacThreshold As Short, ByRef pMinEncVel As Double, ByRef pTime As Integer) As Short
    Public Declare Function GT_EnableEncResponseCheck Lib "gts.dll" (ByVal control As Short) As Short
    Public Declare Function GT_DisableEncResponseCheck Lib "gts.dll" (ByVal control As Short) As Short

    Public Declare Function GT_2DCompareMode Lib "gts.dll" (ByVal chn As Short, ByVal mode As Short) As Short
    Public Declare Function GT_2DComparePulse Lib "gts.dll" (ByVal chn As Short, ByVal level As Short, ByVal outputType As Short, ByVal time As Short) As Short
    Public Declare Function GT_2DCompareStop Lib "gts.dll" (ByVal chn As Short)
    Public Declare Function GT_2DCompareClear Lib "gts.dll" (ByVal chn As Short)
    Public Declare Function GT_2DCompareStatus Lib "gts.dll" (ByVal chn As Short, ByRef pStatus As Short, ByRef pCount As Integer, ByRef pFifo As Short, ByRef pFifoCount As Short, Optional ByRef pBufCount As Short = Nothing) As Short
    Public Declare Function GT_2DCompareSetPrm Lib "gts.dll" (ByVal chn As Short, ByRef pPrm As T2DComparePrm) As Short
    Public Declare Function GT_2DCompareData Lib "gts.dll" (ByVal chn As Short, ByVal count As Short, ByRef pBuf As T2DCompareData, ByVal fifo As Short) As Short
    Public Declare Function GT_2DCompareStart Lib "gts.dll" (ByVal chn As Short) As Short
    Public Declare Function GT_2DCompareClearData Lib "gts.dll" (ByVal chn As Short) As Short
    Public Declare Function GT_2DCompareSetPreOutTime Lib "gts.dll" (ByVal chn As Short, ByVal preOutputTime As Double) As Short

    Public Declare Function GT_SetAxisMode Lib "gts.dll" (ByVal axis As Short, ByVal mode As Short) As Short
    Public Declare Function GT_GetAxisMode Lib "gts.dll" (ByVal axis As Short, ByVal pMode As Short) As Short
    Public Declare Function GT_SetHSIOOpt Lib "gts.dll" (ByVal value As UShort, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_GetHSIOOpt Lib "gts.dll" (ByRef pValue As UShort, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_LaserPowerMode Lib "gts.dll" (ByVal laserPowerMode As Short, ByVal maxValue As Double, ByVal minValue As Double, Optional ByVal channel As Short = 0, Optional ByVal delaymode As Short = 0) As Short
    Public Declare Function GT_LaserPrfCmd Lib "gts.dll" (ByVal outputCmd As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_LaserOutFrq Lib "gts.dll" (ByVal outFrq As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetPulseWidth Lib "gts.dll" (ByVal width As UInteger, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetWaitPulse Lib "gts.dll" (ByVal mode As UShort, ByVal waitPulseFrq As Double, ByVal waitPulseDuty As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetPreVltg Lib "gts.dll" (ByVal mode As UShort, ByVal voltageValue As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetLevelDelay Lib "gts.dll" (ByVal offDelay As UShort, ByVal onDelay As UShort, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_EnaFPK Lib "gts.dll" (ByVal time1 As UShort, ByVal time2 As UShort, ByVal laserOffDelay As UShort, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_DisFPK Lib "gts.dll" (Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetLaserDisMode Lib "gts.dll" (ByVal mode As Short, ByVal source As Short, ByRef pPos As Integer, ByRef pScale As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetLaserDisRatio Lib "gts.dll" (ByRef pRatio As Double, ByVal minPower As Double, ByVal maxPower As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_SetWaitPulseEx Lib "gts.dll" (ByVal mode As UShort, ByVal waitPulseFrq As Double, ByVal waitPulseDuty As Double) As Short
    Public Declare Function GT_SetLaserMode Lib "gts.dll" (ByVal mode As Short) As Short
    Public Declare Function GT_SetLaserFollowSpline Lib "gts.dll" (ByVal tableId As Short, ByVal n As Integer, ByRef pX As Double, ByRef pY As Double, ByVal beginValue As Double, ByVal endValue As Double, Optional ByVal channel As Short = 0) As Short
    Public Declare Function GT_GetLaserFollowSpline Lib "gts.dll" (ByVal tableId As Short, ByVal n As Integer, ByRef pX As Double, ByRef pY As Double, ByRef pA As Double, ByRef pB As Double, ByRef pC As Double, ByRef pCount As Integer, Optional ByVal channel As Short = 0) As Short

    'ExtMul
    Public Declare Function GT_OpenExtMdl Lib "gts.dll" (Optional ByRef pDllName As String = Nothing) As Short
    Public Declare Function GT_CloseExtMdl Lib "gts.dll" () As Short
    Public Declare Function GT_SwitchtoCardNoExtMdl Lib "gts.dll" (ByVal card As Short) As Short
    Public Declare Function GT_ResetExtMdl Lib "gts.dll" () As Short
    Public Declare Function GT_LoadExtConfig Lib "gts.dll" (ByRef pFileName As String) As Short
    Public Declare Function GT_SetExtIoValue Lib "gts.dll" (ByVal mdl As Short, ByVal value As UShort) As Short
    Public Declare Function GT_GetExtIoValue Lib "gts.dll" (ByVal mdl As Short, ByRef pValue As UShort) As Short
    Public Declare Function GT_SetExtIoBit Lib "gts.dll" (ByVal mdl As Short, ByVal index As Short, ByVal value As UShort) As Short
    Public Declare Function GT_GetExtIoBit Lib "gts.dll" (ByVal mdl As Short, ByVal index As Short, ByRef pValue As UShort) As Short
    Public Declare Function GT_GetExtAdValue Lib "gts.dll" (ByVal mdl As Short, ByVal chn As Short, ByRef pValue As UShort) As Short
    Public Declare Function GT_GetExtAdVoltage Lib "gts.dll" (ByVal mdl As Short, ByVal chn As Short, ByRef pValue As Double) As Short
    Public Declare Function GT_SetExtDaValue Lib "gts.dll" (ByVal mdl As Short, ByVal chn As Short, ByVal value As UShort) As Short
    Public Declare Function GT_SetExtDaVoltage Lib "gts.dll" (ByVal mdl As Short, ByVal chn As Short, ByVal value As Double) As Short
    Public Declare Function GT_GetStsExtMdl Lib "gts.dll" (ByVal mdl As Short, ByVal chn As Short, ByRef pStatus As UShort) As Short
    Public Declare Function GT_GetExtDoValue Lib "gts.dll" (ByVal mdl As Short, ByRef pValue As UShort) As Short
    Public Declare Function GT_GetExtMdlMode Lib "gts.dll" (ByRef pMode As Short) As Short
    Public Declare Function GT_SetExtMdlMode Lib "gts.dll" (ByVal mode As Short) As Short
    Public Declare Function GT_UploadConfig Lib "gts.dll" () As Short
    Public Declare Function GT_DownloadConfig Lib "gts.dll" () As Short

    Public Declare Function GT_GetUuid Lib "gts.dll" (ByRef pCode As String, ByVal count As Short) As Short
    Public Declare Function GT_SetUuid Lib "gts.dll" (ByRef pCode As String, ByVal count As Short) As Short

    '2D Compensate
    Public Structure TCompensate2DTable
        Dim count1 As Short
        Dim count2 As Short
        Dim posBegin1 As Integer
        Dim posBegin2 As Integer
        Dim step1 As Integer
        Dim step2 As Integer                            
    End Structure
    Public Structure TCompensate2D 
        Dim enable As Short
        Dim tableIndex As Short
        Dim axisType1 As Short
        Dim axisType2 As Short
        Dim axisIndex1 As Short
        Dim axisIndex2 As Short                    
    End Structure
    Public Declare Function GT_SetCompensate2DTable Lib "gts.dll" (ByVal tableIndex As Short, ByRef pTable As TCompensate2DTable, ByRef pData As Integer, Optional ByVal externComp As Short = 0) As Short
    Public Declare Function GT_GetCompensate2DTable Lib "gts.dll" (ByVal tableIndex As Short, ByRef pTable As TCompensate2DTable, Optional ByRef pExternComp As Short = Nothing) As Short
    Public Declare Function GT_SetCompensate2D Lib "gts.dll" (ByVal axis As Short, ByRef pComp2d As TCompensate2D) As Short
    Public Declare Function GT_GetCompensate2D Lib "gts.dll" (ByVal axis As Short, ByRef pComp2d As TCompensate2D) As Short
    Public Declare Function GT_GetCompensate2DValue Lib "gts.dll" (ByVal axis As Short, ByRef pValue As Double) As Short

    'Smart Home
    Public Const HOME_STAGE_IDLE As Short = 0
    Public Const HOME_STAGE_START As Short = 1
    Public Const HOME_STAGE_ON_HOME_LIMIT_ESCAPE = 2
    Public Const HOME_STAGE_SEARCH_LIMIT As Short = 10
    Public Const HOME_STAGE_SEARCH_LIMIT_STOP As Short = 11
    Public Const HOME_STAGE_SEARCH_LIMIT_ESCAPE As Short = 13
    Public Const HOME_STAGE_SEARCH_LIMIT_RETURN As Short = 15
    Public Const HOME_STAGE_SEARCH_LIMIT_RETURN_STOP As Short = 16
    Public Const HOME_STAGE_SEARCH_HOME As Short = 20
    Public Const HOME_STAGE_SEARCH_HOME_STOP = 22
    Public Const HOME_STAGE_SEARCH_HOME_RETURN As Short = 25
    Public Const HOME_STAGE_SEARCH_INDEX As Short = 30
    Public Const HOME_STAGE_SEARCH_GPI As Short = 40
    Public Const HOME_STAGE_SEARCH_GPI_RETURN As Short = 45
    Public Const HOME_STAGE_GO_HOME As Short = 80
    Public Const HOME_STAGE_END As Short = 100
    Public Const HOME_ERROR_NONE As Short = 0
    Public Const HOME_ERROR_NOT_TRAP_MODE As Short = 1
    Public Const HOME_ERROR_DISABLE As Short = 2
    Public Const HOME_ERROR_ALARM As Short = 3
    Public Const HOME_ERROR_STOP As Short = 4
    Public Const HOME_ERROR_STAGE As Short = 5
    Public Const HOME_ERROR_HOME_MODE As Short = 6
    Public Const HOME_ERROR_SET_CAPTURE_HOME As Short = 7
    Public Const HOME_ERROR_NO_HOME As Short = 8
    Public Const HOME_ERROR_SET_CAPTURE_INDEX As Short = 9
    Public Const HOME_ERROR_NO_INDEX As Short = 10
    Public Const HOME_MODE_LIMIT As Short = 10
    Public Const HOME_MODE_LIMIT_HOME As Short = 11
    Public Const HOME_MODE_LIMIT_INDEX As Short = 12
    Public Const HOME_MODE_LIMIT_HOME_INDEX As Short = 13
    Public Const HOME_MODE_HOME As Short = 20
    Public Const HOME_MODE_HOME_INDEX As Short = 22
    Public Const HOME_MODE_INDEX As Short = 30
    Public Const HOME_MODE_FORCED_HOME = 40
    Public Const HOME_MODE_FORCED_HOME_INDEX = 41

    Public Structure THomePrm
        Dim mode As Short
        Dim moveDir As Short
        Dim indexDir As Short
        Dim edge As Short
        Dim triggerIndex As Short
        Dim pad1_1 As Short
        Dim pad1_2 As Short
        Dim pad1_3 As Short
        Dim velHigh As Double
        Dim velLow As Double
        Dim acc As Double
        Dim dec As Double
        Dim smoothTime As Short
        Dim pad2_1 As Short
        Dim pad2_2 As Short
        Dim pad2_3 As Short
        Dim homeOffset As Integer
        Dim searchHomeDistance As Integer
        Dim searchIndexDistance As Integer
        Dim escapeStep As Integer
        Dim pad3_1 As Integer
        Dim pad3_2 As Integer
        Dim pad3_3 As Integer
    End Structure
    Public Structure THomeStatus
        Dim run As Short
        Dim stage As Short
        Dim iError As Short
        Dim pad1 As Short
        Dim capturePos As Integer
        Dim targetPos As Integer
    End Structure

    Public Declare Function GT_GoHome Lib "gts.dll" (ByVal axis As Short, ByRef pHomePrm As THomePrm) As Short
    Public Declare Function GT_GetHomePrm Lib "gts.dll" (ByVal axis As Short, ByRef pHomePrm As THomePrm) As Short
    Public Declare Function GT_GetHomeStatus Lib "gts.dll" (ByVal axis As Short, ByRef pHomeStatus As THomeStatus) As Short

    'Extern Control
    Public Structure TControlConfigEx
        Dim refType As Short
        Dim refIndex As Short
        Dim feedbackType As Short
        Dim feedbackIndex As Short
        Dim errorLimit As Integer
        Dim feedbackSmooth As Short
        Dim controlSmooth As Short
    End Structure
    Public Declare Function GT_SetControlConfigEx Lib "gts.dll" (ByVal control As Short, ByRef pControl As TControlConfigEx) As Short
    Public Declare Function GT_GetControlConfigEx Lib "gts.dll" (ByVal control As Short, ByRef pControl As TControlConfigEx) As Short

    'Adc filter
    Public Structure TAdcConfig
        Dim active As Short
        Dim reverse As Short
        Dim a As Double
        Dim b As Double
        Dim filterMode As Short
    End Structure
    Public Declare Function GT_SetAdcConfig Lib "gts.dll" (ByVal adc As Short, ByRef pAdc As TAdcConfig) As Short
    Public Declare Function GT_GetAdcConfig Lib "gts.dll" (ByVal adc As Short, ByRef pAdc As TAdcConfig) As Short
    Public Declare Function GT_SetAdcFilterPrm Lib "gts.dll" (ByVal adc As Short, ByVal k As Double) As Short
    Public Declare Function GT_GetAdcFilterPrm Lib "gts.dll" (ByVal adc As Short, ByRef pk As Double) As Short

    'Superimposed
    Public Declare Function GT_SetControlSuperimposed Lib "gts.dll" (ByVal control As Short, ByVal superimposedType As Short, ByVal superimposedIndex As Short) As Short
    Public Declare Function GT_GetControlSuperimposed Lib "gts.dll" (ByVal control As Short, ByRef pSuperimposedType As Short, ByRef pSuperimposedIndex As Short) As Short

    ''
    Public Declare Function GT_ZeroLaserOnTime Lib "gts.dll" (ByVal channel As Short) As Short
    Public Declare Function GT_GetLaserOnTime Lib "gts.dll" (ByVal channel As Short, ByRef pTime As UInteger) As Short
    
    Public Declare Function GT_SetProfileScale Lib "gts.dll" (ByVal axis As Short, ByVal alpha As Integer, ByVal beta As Integer) As Short
    Public Declare Function GT_GetProfileScale Lib "gts.dll" (ByVal axis As Short, ByRef pAlpha As Integer, ByRef pBeta As Integer) As Short
    Public Declare Function GT_SetEncoderScale Lib "gts.dll" (ByVal encoder As Short, ByVal alpha As Integer, ByVal beta As Integer) As Short
    Public Declare Function GT_GetEncoderScale Lib "gts.dll" (ByVal encoder As Short, ByRef pAlpha As Integer, ByRef pBeta As Integer) As Short
		
		Public Declare Function GT_MultiAxisOn Lib "gts.dll" (ByVal mask As Integer) As Short
		Public Declare Function GT_MultiAxisOff Lib "gts.dll" (ByVal mask As Integer) As Short
		Public Declare Function GT_SetAxisOnDelayTime Lib "gts.dll" (ByVal ms As UShort) As Short
		Public Declare Function GT_GetAxisOnDelayTime Lib "gts.dll" (ByRef pMs As UShort) As Short
		
		Public Declare Function GT_SetLaserDisTable1D Lib "gts.dll" (ByVal count As Short, ByRef pRatio As Double, ByRef pPos As Double, ByVal minPower As Double, ByVal maxPower As Double,ByRef pLimitPower As Double, Optional ByVal channel As Short = 0) As Short
		Public Declare Function GT_SetLaserDisTable2D Lib "gts.dll" (ByRef axisIndex As Short, ByRef count As Short, ByRef pRatio As Double, ByRef pXPos As Integer, ByRef pYPos As Integer,ByVal minPower As Double, ByVal maxPower As Double, ByRef pLimitPower As Double, Optional ByVal channel As Short = 0) As Short
		Public Declare Function GT_SetLaserDisTable2DEx Lib "gts.dll" (ByRef axisIndex As Short, ByRef count As Short, ByRef pRatio As Double, ByRef posBegin As Integer, ByRef posStep As Integer,ByVal minPower As Double, ByVal maxPower As Double, ByRef pLimitPower As Double, Optional ByVal channel As Short = 0) As Short
		
		Public Declare Function GT_SetLaserCrdMap Lib "gts.dll" (ByVal channel As Short, ByVal map As Short) As Short
		Public Declare Function GT_GetLaserCrdMap Lib "gts.dll" (ByVal channel As Short, ByRef pMap As Short) As Short
		
		'AutoFocus
		Public Declare Function GT_AutoFocus Lib "gts.dll" (ByVal mode As UShort, ByVal kp As Double, ByVal reverse As Short, ByVal channel As Short) As Short
		Public Declare Function GT_SetAutoFocusRefVol Lib "gts.dll" (ByVal refVol As Double, ByVal maxVol As Double, ByVal minVol As Double, ByVal channel As Short) As Short
		Public Declare Function GT_GetAutoFocusStatus Lib "gts.dll" (ByRef pStatus As UShort, ByVal count As Short) As Short
		Public Declare Function GT_ConfigAutoFocus Lib "gts.dll" (ByVal chnAdc As Short, ByVal channel As Short) As Short
		Public Declare Function GT_SetAutoFocusAuxPrm Lib "gts.dll" (ByVal kf As Double, ByVal kd As Double, ByVal limitKd As Double, ByVal channel As Short) As Short
		
		Public Declare Function GT_Delay Lib "gts.dll" (ByVal time As UShort) As Short
		Public Declare Function GT_DelayHighPrecision Lib "gts.dll" (ByVal time As UShort) As Short
		
		Public Declare Function GT_SetCrdBufferMode Lib "gts.dll" (ByVal crd As Short, ByVal bufferMode As Short, ByVal fifo As Short) As Short
		Public Declare Function GT_GetCrdBufferMode Lib "gts.dll" (ByVal crd As Short, ByRef pBufferMode As Short, ByVal fifo As Short) As Short
		Public Declare Function GT_GetCrdSegmentTime Lib "gts.dll" (ByVal crd As Short, ByVal segmentIndex As Integer, ByRef pSegmentTime As Double, ByRef pSegmentNumber As Integer, ByVal fifo As Short) As Short
		Public Declare Function GT_GetCrdTime Lib "gts.dll" (ByVal crd As Short, ByRef pTime As TCrdTime, ByVal fifo As Short) As Short
		
		Public Declare Function GT_SetLeadScrewLink Lib "gts.dll" (ByVal axis As Short, ByVal link As Short) As Short
		Public Declare Function GT_GetLeadScrewLink Lib "gts.dll" (ByVal axis As Short, ByRef pLink As Short) As Short


    'Standard Home

    Public Const STANDARD_HOME_STAGE_IDLE As Short = 0
    Public Const STANDARD_HOME_STAGE_START As Short = 1
    Public Const STANDARD_HOME_STAGE_SEARCH_HOME As Short = 20
    Public Const STANDARD_HOME_STAGE_SEARCH_INDEX As Short = 30
    Public Const STANDARD_HOME_STAGE_GO_HOME As Short = 80
    Public Const STANDARD_HOME_STAGE_END As Short = 100
    Public Const STANDARD_HOME_STAGE_START_CHECK As Short = -1
    Public Const STANDARD_HOME_STAGE_CHECKING As Short = -2


    Public Const STANDARD_HOME_ERROR_NONE As Short = 0
    Public Const STANDARD_HOME_ERROR_DISABLE As Short = 10
    Public Const STANDARD_HOME_ERROR_ALARM As Short = 20
    Public Const STANDARD_HOME_ERROR_STOP As Short = 30
    Public Const STANDARD_HOME_ERROR_ON_LIMIT As Short = 40
    Public Const STANDARD_HOME_ERROR_NO_HOME As Short = 50
    Public Const STANDARD_HOME_ERROR_NO_INDEX As Short = 60
    Public Const STANDARD_HOME_ERROR_NO_LIMIT As Short = 70
    Public Const STANDARD_HOME_ERROR_ENCODER_DIR_SCALE As Short = -1
    Public Structure TStandardHomePrm
        Dim mode As Short
        Dim highSpeed As Double
        Dim lowSpeed As Double
        Dim acc As Double
        Dim offset As Integer
        Dim check As Short
        Dim autoZeroPos As Short
        Dim motorStopDelay As Integer
        Dim pad1 As Short
        Dim pad2 As Short
        Dim pad3 As Short
    End Structure
    Public Structure TStandardHomeStatus
        Dim run As Short
        Dim stage As Short
        Dim err As Short
        Dim pad1 As Short
        Dim pad2 As Short
        Dim pad3 As Short
        Dim capturePos As Integer
        Dim targetPos As Integer
    End Structure

    Public Declare Function GT_ExecuteStandardHome Lib "gts.dll" (ByVal axis As Short, ByRef pHomePrm As TStandardHomePrm) As Short

    Public Declare Function GT_GetStandardHomePrm Lib "gts.dll" (ByVal axis As Short, ByRef pHomePrm As TStandardHomePrm) As Short

    Public Declare Function GT_GetStandardHomeStatus Lib "gts.dll" (ByVal axis As Short, ByRef pHomeStatus As TStandardHomeStatus) As Short

    'DMA
    Public Declare Function GT_CrdHsOn Lib "gts.dll" (ByVal crd As Short, ByVal fifo As Short, ByVal link As Short, ByVal threshold As UShort, ByVal lookAheadInMc As Short) As Short

    Public Declare Function GT_CrdHsOff Lib "gts.dll" (ByVal crd As Short, ByVal fifo As Short) As Short
End Module
