/* file: osobjs.inc, automatically generated by genTMS570SafeCtxAS.exe, Version: 5.07 */
/* configuration read from: C:\Users\cz8l9t\AppData\Local\Temp\~cfg4_314_EPS.ecuc.arxml.oil */
/* generation at  : Wed May 18 15:08:50 2016 */
/* Unlimited license CBD1010124 for Nxtr Automotive */
/* Implementation: TMS570LS3x */
/* Version of general code: 5.23c */

     . = align(16384);   /* align to region size 16384 */
     _ossAppluDataStartAp_10=.;
     /* Nxtr patch for TypeH Data */
     *(.ossDataAp_10:noinit:typeH) {START(Lnk_TypeH10_Start), SIZE(Lnk_TypeH10_Size)}
     *(.ossDataAp_10:noinit)
     _ossAppluDataEndAp_10=.;
     _ossAppluDataSizeAp_10 = _ossAppluDataEndAp_10 - _ossAppluDataStartAp_10 + 1;
     . = . + 1;
     . = align(16384); /* Use 8 subregions with size 2048*/

     . = align(16384);   /* align to region size 16384 */
     _ossAppluDataStartAp_9=.;
     /* Nxtr patch for TypeH Data */
     *(.ossDataAp_9:noinit:typeH) {START(Lnk_TypeH9_Start), SIZE(Lnk_TypeH9_Size)}
     *(.ossDataAp_9:noinit)
     _Hidden_Ram_Start = .;
     *(.hidden)
     _Hidden_Ram_End = .;
     *(.bss)
     _ossAppluDataEndAp_9=.;
     _ossAppluDataSizeAp_9 = _ossAppluDataEndAp_9 - _ossAppluDataStartAp_9 + 1;
     . = . + 1;
     . = align(16384); /* Use 8 subregions with size 2048*/

     . = align(2048);   /* align to region size 2048 */
     *(.ossTaskStackTask_10ms_SchM9:noinit) {START(_ossTaskStackStartTask_10ms_SchM9), SIZE(_ossTaskStackSizeTask_10ms_SchM9)}
     _ossTaskStackEndTask_10ms_SchM9=.;
     . = . + 1;
     . = align(2048); /* Use 8 subregions with size 256*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_2msB_10:noinit) {START(_ossTaskStackStartTask_2msB_10), SIZE(_ossTaskStackSizeTask_2msB_10)}
     _ossTaskStackEndTask_2msB_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_4ms_SchM0:noinit) {START(_ossTaskStackStartTask_4ms_SchM0), SIZE(_ossTaskStackSizeTask_4ms_SchM0)}
     _ossTaskStackEndTask_4ms_SchM0=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Init_10:noinit) {START(_ossTaskStackStartTask_Init_10), SIZE(_ossTaskStackSizeTask_Init_10)}
     _ossTaskStackEndTask_Init_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Init_8:noinit) {START(_ossTaskStackStartTask_Init_8), SIZE(_ossTaskStackSizeTask_Init_8)}
     _ossTaskStackEndTask_Init_8=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Init_9:noinit) {START(_ossTaskStackStartTask_Init_9), SIZE(_ossTaskStackSizeTask_Init_9)}
     _ossTaskStackEndTask_Init_9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_2ms_10:noinit) {START(_ossTaskStackStartTask_2ms_10), SIZE(_ossTaskStackSizeTask_2ms_10)}
     _ossTaskStackEndTask_2ms_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_2ms_8:noinit) {START(_ossTaskStackStartTask_2ms_8), SIZE(_ossTaskStackSizeTask_2ms_8)}
     _ossTaskStackEndTask_2ms_8=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_2ms_9:noinit) {START(_ossTaskStackStartTask_2ms_9), SIZE(_ossTaskStackSizeTask_2ms_9)}
     _ossTaskStackEndTask_2ms_9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_4ms_10:noinit) {START(_ossTaskStackStartTask_4ms_10), SIZE(_ossTaskStackSizeTask_4ms_10)}
     _ossTaskStackEndTask_4ms_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_10ms_10:noinit) {START(_ossTaskStackStartTask_10ms_10), SIZE(_ossTaskStackSizeTask_10ms_10)}
     _ossTaskStackEndTask_10ms_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_10ms_9:noinit) {START(_ossTaskStackStartTask_10ms_9), SIZE(_ossTaskStackSizeTask_10ms_9)}
     _ossTaskStackEndTask_10ms_9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_100ms_10:noinit) {START(_ossTaskStackStartTask_100ms_10), SIZE(_ossTaskStackSizeTask_100ms_10)}
     _ossTaskStackEndTask_100ms_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_100ms_8:noinit) {START(_ossTaskStackStartTask_100ms_8), SIZE(_ossTaskStackSizeTask_100ms_8)}
     _ossTaskStackEndTask_100ms_8=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_100ms_9:noinit) {START(_ossTaskStackStartTask_100ms_9), SIZE(_ossTaskStackSizeTask_100ms_9)}
     _ossTaskStackEndTask_100ms_9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_TrnsB_9:noinit) {START(_ossTaskStackStartTask_TrnsB_9), SIZE(_ossTaskStackSizeTask_TrnsB_9)}
     _ossTaskStackEndTask_TrnsB_9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Trans_10:noinit) {START(_ossTaskStackStartTask_Trans_10), SIZE(_ossTaskStackSizeTask_Trans_10)}
     _ossTaskStackEndTask_Trans_10=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Trans_8:noinit) {START(_ossTaskStackStartTask_Trans_8), SIZE(_ossTaskStackSizeTask_Trans_8)}
     _ossTaskStackEndTask_Trans_8=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Trans_9:noinit) {START(_ossTaskStackStartTask_Trans_9), SIZE(_ossTaskStackSizeTask_Trans_9)}
     _ossTaskStackEndTask_Trans_9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_100ms_SchM9:noinit) {START(_ossTaskStackStartTask_100ms_SchM9), SIZE(_ossTaskStackSizeTask_100ms_SchM9)}
     _ossTaskStackEndTask_100ms_SchM9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_100ms_SchM0:noinit) {START(_ossTaskStackStartTask_100ms_SchM0), SIZE(_ossTaskStackSizeTask_100ms_SchM0)}
     _ossTaskStackEndTask_100ms_SchM0=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Init_SchM9:noinit) {START(_ossTaskStackStartTask_Init_SchM9), SIZE(_ossTaskStackSizeTask_Init_SchM9)}
     _ossTaskStackEndTask_Init_SchM9=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossTaskStackTask_Bkgnd:noinit) {START(_ossTaskStackStartTask_Bkgnd), SIZE(_ossTaskStackSizeTask_Bkgnd)}
     _ossTaskStackEndTask_Bkgnd=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossIRQHd0Stack:noinit) {START(_ossIRQHd0StackStartIRQHd0), SIZE(_ossIRQHd0StackSizeIRQHd0)}
     _ossIRQHd0StackEndIRQHd0=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossIRQHd1Stack:noinit) {START(_ossIRQHd1StackStartIRQHd1), SIZE(_ossIRQHd1StackSizeIRQHd1)}
     _ossIRQHd1StackEndIRQHd1=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossIRQHd2Stack:noinit) {START(_ossIRQHd2StackStartIRQHd2), SIZE(_ossIRQHd2StackSizeIRQHd2)}
     _ossIRQHd2StackEndIRQHd2=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossIRQHd3Stack:noinit) {START(_ossIRQHd3StackStartIRQHd3), SIZE(_ossIRQHd3StackSizeIRQHd3)}
     _ossIRQHd3StackEndIRQHd3=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossIRQHd4Stack:noinit) {START(_ossIRQHd4StackStartIRQHd4), SIZE(_ossIRQHd4StackSizeIRQHd4)}
     _ossIRQHd4StackEndIRQHd4=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossIRQHd5Stack:noinit) {START(_ossIRQHd5StackStartIRQHd5), SIZE(_ossIRQHd5StackSizeIRQHd5)}
     _ossIRQHd5StackEndIRQHd5=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.osdata) {START(_osOSDataStartOSData), SIZE(_osOSDataSizeOSData)}
     _osOSDataEndOSData=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(1024);   /* align to region size 1024 */
     *(.ossGlobalShared) {START(_osGlobalSharedStartGlobalShared), SIZE(_osGlobalSharedSizeGlobalShared)}
     _osGlobalSharedEndGlobalShared=.;
     . = . + 1;
     . = align(1024); /* Use 8 subregions with size 128*/

     . = align(512);   /* align to region size 512 */
     _ossAppluDataStartAp_8=.;
     /* Nxtr patch for TypeH Data */
     *(.ossDataAp_8:noinit:typeH) {START(Lnk_TypeH8_Start), SIZE(Lnk_TypeH8_Size)}
     *(.ossDataAp_8:noinit)
     _ossAppluDataEndAp_8=.;
     _ossAppluDataSizeAp_8 = _ossAppluDataEndAp_8 - _ossAppluDataStartAp_8 + 1;
     . = . + 1;
     . = align(512); /* Use 8 subregions with size 64*/

     . = align(512);   /* align to region size 512 */
     *(.ossNTFTaskStackTask_10ms_SchM9) {START(_ossNTFTaskStackStartTask_10ms_SchM9), SIZE(_ossNTFTaskStackSizeTask_10ms_SchM9)}
     _ossNTFTaskStackEndTask_10ms_SchM9=.;
     . = . + 1;
     . = align(512); /* Use 8 subregions with size 64*/

     . = align(512);   /* align to region size 512 */
     *(.ossNTFTaskStackTask_Init_SchM9) {START(_ossNTFTaskStackStartTask_Init_SchM9), SIZE(_ossNTFTaskStackSizeTask_Init_SchM9)}
     _ossNTFTaskStackEndTask_Init_SchM9=.;
     . = . + 1;
     . = align(512); /* Use 8 subregions with size 64*/

     . = align(512);   /* align to region size 512 */
     *(.ossNTFISRStackDCan1_level0_Irq) {START(_ossNTFISRStackStartDCan1_level0_Irq), SIZE(_ossNTFISRStackSizeDCan1_level0_Irq)}
     _ossNTFISRStackEndDCan1_level0_Irq=.;
     . = . + 1;
     . = align(512); /* Use 8 subregions with size 64*/

     . = align(512);   /* align to region size 512 */
     *(.ossAPIStack) {START(_osAPIStackStartAPIStack), SIZE(_osAPIStackSizeAPIStack)}
     _osAPIStackEndAPIStack=.;
     . = . + 1;
     . = align(512); /* Use 8 subregions with size 64*/

     . = align(256);   /* align to region size 256 */
     *(.ossSystemStack) {START(_osSystemStackStartSystemStack), SIZE(_osSystemStackSizeSystemStack)}
     _osSystemStackEndSystemStack=.;
     . = . + 1;
     . = align(256); /* Use 8 subregions with size 32*/

     . = align(0);   /* align to region size 0 */
     _ossAppluDataStartAp_0=.;
     /* Nxtr patch for TypeH Data */
     *(.ossDataAp_0:noinit:typeH) {START(Lnk_TypeH0_Start), SIZE(Lnk_TypeH0_Size)}
     *(.ossDataAp_0:noinit)
     _ossAppluDataEndAp_0=.;
     _ossAppluDataSizeAp_0 = _ossAppluDataEndAp_0 - _ossAppluDataStartAp_0 + 1;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_2msB_10:noinit) {START(_ossTaskuDataStartTask_2msB_10), SIZE(_ossTaskuDataSizeTask_2msB_10)}
     _ossTaskuDataEndTask_2msB_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_4ms_SchM0:noinit) {START(_ossTaskuDataStartTask_4ms_SchM0), SIZE(_ossTaskuDataSizeTask_4ms_SchM0)}
     _ossTaskuDataEndTask_4ms_SchM0=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Init_10:noinit) {START(_ossTaskuDataStartTask_Init_10), SIZE(_ossTaskuDataSizeTask_Init_10)}
     _ossTaskuDataEndTask_Init_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Init_8:noinit) {START(_ossTaskuDataStartTask_Init_8), SIZE(_ossTaskuDataSizeTask_Init_8)}
     _ossTaskuDataEndTask_Init_8=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Init_9:noinit) {START(_ossTaskuDataStartTask_Init_9), SIZE(_ossTaskuDataSizeTask_Init_9)}
     _ossTaskuDataEndTask_Init_9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_2ms_10:noinit) {START(_ossTaskuDataStartTask_2ms_10), SIZE(_ossTaskuDataSizeTask_2ms_10)}
     _ossTaskuDataEndTask_2ms_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_2ms_8:noinit) {START(_ossTaskuDataStartTask_2ms_8), SIZE(_ossTaskuDataSizeTask_2ms_8)}
     _ossTaskuDataEndTask_2ms_8=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_2ms_9:noinit) {START(_ossTaskuDataStartTask_2ms_9), SIZE(_ossTaskuDataSizeTask_2ms_9)}
     _ossTaskuDataEndTask_2ms_9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_4ms_10:noinit) {START(_ossTaskuDataStartTask_4ms_10), SIZE(_ossTaskuDataSizeTask_4ms_10)}
     _ossTaskuDataEndTask_4ms_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_10ms_10:noinit) {START(_ossTaskuDataStartTask_10ms_10), SIZE(_ossTaskuDataSizeTask_10ms_10)}
     _ossTaskuDataEndTask_10ms_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_10ms_9:noinit) {START(_ossTaskuDataStartTask_10ms_9), SIZE(_ossTaskuDataSizeTask_10ms_9)}
     _ossTaskuDataEndTask_10ms_9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_100ms_10:noinit) {START(_ossTaskuDataStartTask_100ms_10), SIZE(_ossTaskuDataSizeTask_100ms_10)}
     _ossTaskuDataEndTask_100ms_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_100ms_8:noinit) {START(_ossTaskuDataStartTask_100ms_8), SIZE(_ossTaskuDataSizeTask_100ms_8)}
     _ossTaskuDataEndTask_100ms_8=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_100ms_9:noinit) {START(_ossTaskuDataStartTask_100ms_9), SIZE(_ossTaskuDataSizeTask_100ms_9)}
     _ossTaskuDataEndTask_100ms_9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_TrnsB_9:noinit) {START(_ossTaskuDataStartTask_TrnsB_9), SIZE(_ossTaskuDataSizeTask_TrnsB_9)}
     _ossTaskuDataEndTask_TrnsB_9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Trans_10:noinit) {START(_ossTaskuDataStartTask_Trans_10), SIZE(_ossTaskuDataSizeTask_Trans_10)}
     _ossTaskuDataEndTask_Trans_10=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Trans_8:noinit) {START(_ossTaskuDataStartTask_Trans_8), SIZE(_ossTaskuDataSizeTask_Trans_8)}
     _ossTaskuDataEndTask_Trans_8=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Trans_9:noinit) {START(_ossTaskuDataStartTask_Trans_9), SIZE(_ossTaskuDataSizeTask_Trans_9)}
     _ossTaskuDataEndTask_Trans_9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_100ms_SchM9:noinit) {START(_ossTaskuDataStartTask_100ms_SchM9), SIZE(_ossTaskuDataSizeTask_100ms_SchM9)}
     _ossTaskuDataEndTask_100ms_SchM9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_10ms_SchM9:noinit) {START(_ossTaskuDataStartTask_10ms_SchM9), SIZE(_ossTaskuDataSizeTask_10ms_SchM9)}
     _ossTaskuDataEndTask_10ms_SchM9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_100ms_SchM0:noinit) {START(_ossTaskuDataStartTask_100ms_SchM0), SIZE(_ossTaskuDataSizeTask_100ms_SchM0)}
     _ossTaskuDataEndTask_100ms_SchM0=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Init_SchM9:noinit) {START(_ossTaskuDataStartTask_Init_SchM9), SIZE(_ossTaskuDataSizeTask_Init_SchM9)}
     _ossTaskuDataEndTask_Init_SchM9=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataTask_Bkgnd:noinit) {START(_ossTaskuDataStartTask_Bkgnd), SIZE(_ossTaskuDataSizeTask_Bkgnd)}
     _ossTaskuDataEndTask_Bkgnd=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataIsr_MtrCtrl:noinit) {START(_ossISRuDataStartIsr_MtrCtrl), SIZE(_ossISRuDataSizeIsr_MtrCtrl)}
     _ossISRuDataEndIsr_MtrCtrl=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataDCan1_level0_Irq:noinit) {START(_ossISRuDataStartDCan1_level0_Irq), SIZE(_ossISRuDataSizeDCan1_level0_Irq)}
     _ossISRuDataEndDCan1_level0_Irq=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataIsr_ESMH:noinit) {START(_ossISRuDataStartIsr_ESMH), SIZE(_ossISRuDataSizeIsr_ESMH)}
     _ossISRuDataEndIsr_ESMH=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataGpt_IsrInt0:noinit) {START(_ossISRuDataStartGpt_IsrInt0), SIZE(_ossISRuDataSizeGpt_IsrInt0)}
     _ossISRuDataEndGpt_IsrInt0=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataIsr_ESML:noinit) {START(_ossISRuDataStartIsr_ESML), SIZE(_ossISRuDataSizeIsr_ESML)}
     _ossISRuDataEndIsr_ESML=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataFlsTst_CrcIrq:noinit) {START(_ossISRuDataStartFlsTst_CrcIrq), SIZE(_ossISRuDataSizeFlsTst_CrcIrq)}
     _ossISRuDataEndFlsTst_CrcIrq=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataDCan2_level0_Irq:noinit) {START(_ossISRuDataStartDCan2_level0_Irq), SIZE(_ossISRuDataSizeDCan2_level0_Irq)}
     _ossISRuDataEndDCan2_level0_Irq=.;
     . = . + 1;
     . = align(0); /* Use no subregions */

     . = align(0);   /* align to region size 0 */
     *(.ossDataIsr_I2c:noinit) {START(_ossISRuDataStartIsr_I2c), SIZE(_ossISRuDataSizeIsr_I2c)}
     _ossISRuDataEndIsr_I2c=.;
     . = . + 1;
     . = align(0); /* Use no subregions */
