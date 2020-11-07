# Kirikiroid2




## Tree
```shell
.
├── cocos
│   └── kr2
│       ├── cocosstudio
│       │   ├── img
│       │   │   ├── about_icon.png
│       │   │   ├── back_btn_off.png
│       │   │   ├── back_btn_on.png
│       │   │   ├── back_icon.png
│       │   │   ├── Cancel_Normal.png
│       │   │   ├── Cancel_Press.png
│       │   │   ├── CheckBox_Disable.png
│       │   │   ├── CheckBoxNode_Normal.png
│       │   │   ├── CheckBoxNode_Press.png
│       │   │   ├── CheckBox_Normal.png
│       │   │   ├── CheckBox_Press.png
│       │   │   ├── circle_arrow_normal.png
│       │   │   ├── circle_arrow.png
│       │   │   ├── circle_arrow_press.png
│       │   │   ├── circle_white.png
│       │   │   ├── empty.png
│       │   │   ├── exit_icon.png
│       │   │   ├── gray.png
│       │   │   ├── keyboard_icon.png
│       │   │   ├── menu_handler.png
│       │   │   ├── menu_icon.png
│       │   │   ├── menu_press.png
│       │   │   ├── mouse_2btn.png
│       │   │   ├── mouse_icon.png
│       │   │   ├── mouse_left_btn.png
│       │   │   ├── mouse_right_btn.png
│       │   │   ├── right_triangle.png
│       │   │   ├── syssetting_btn_ff.png
│       │   │   ├── syssetting_btn_on.png
│       │   │   ├── touch1.png
│       │   │   ├── touch2.png
│       │   │   ├── touch_icon.png
│       │   │   ├── triangle.png
│       │   │   ├── white.png
│       │   │   └── windows_icon.png
│       │   ├── mouse_2btn.png
│       │   ├── mouse_left_btn.png
│       │   ├── mouse_right_btn.png
│       │   └── ui
│       │       ├── BottomBar.csd
│       │       ├── BottomBarTextInput.csd
│       │       ├── CheckListDialog.csd
│       │       ├── comctrl
│       │       │   ├── CheckBoxItem.csd
│       │       │   ├── SelectListItem.csd
│       │       │   ├── SeperateItem.csd
│       │       │   ├── SliderIconItem.csd
│       │       │   ├── SliderTextItem.csd
│       │       │   └── SubDirItem.csd
│       │       ├── FileItem.csd
│       │       ├── FileManageMenu.csd
│       │       ├── GameMenu.csd
│       │       ├── help
│       │       │   ├── AllTips.csd
│       │       │   ├── MouseModeTips.csd
│       │       │   ├── ScreenModeTips.csd
│       │       │   └── TouchModeTips.csd
│       │       ├── KeySelect.csd
│       │       ├── ListItem.csd
│       │       ├── ListView.csd
│       │       ├── MainFileSelector.csd
│       │       ├── MediaPlayerBody.csd
│       │       ├── MediaPlayerFoot.csd
│       │       ├── MediaPlayerNavi.csd
│       │       ├── MenuList.csd
│       │       ├── MessageBox.csd
│       │       ├── NaviBar.csd
│       │       ├── NaviBarWithMenu.csd
│       │       ├── ProgressBox.csd
│       │       ├── RecentListItem.csd
│       │       ├── SelectList.csd
│       │       ├── SelectListItem.csd
│       │       ├── TableView.csd
│       │       ├── TextPairInput.csd
│       │       └── WinMgrOverlay.csd
│       ├── kr2.ccs
│       ├── kr2.cfg
│       └── Resources
│           └── res
│               └── locale
│                   ├── en_us.xml
│                   ├── ja_jp.xml
│                   ├── zh_cn.xml
│                   └── zh_tw.xml
├── LICENSE
├── project
│   └── android
│       ├── AndroidManifest.xml
│       ├── jni
│       │   ├── Android.mk
│       │   ├── Application.mk
│       │   └── src
│       │       └── SDL_android_main.cpp
│       ├── project.properties
│       └── src
│           └── org
│               └── tvp
│                   └── kirikiri2
│                       ├── Kirikiroid2.java
│                       ├── KR2Activity.java
│                       └── MediaStoreHack.java
├── readme.md
└── src
    ├── core
    │   ├── Android.mk
    │   ├── base
    │   │   ├── 7zArchive.cpp
    │   │   ├── BinaryStream.cpp
    │   │   ├── BinaryStream.h
    │   │   ├── CharacterSet.cpp
    │   │   ├── CharacterSet.h
    │   │   ├── common.h
    │   │   ├── EventIntf.cpp
    │   │   ├── EventIntf.h
    │   │   ├── PluginIntf.cpp
    │   │   ├── PluginIntf.h
    │   │   ├── ScriptMgnIntf.cpp
    │   │   ├── ScriptMgnIntf.h
    │   │   ├── StorageIntf.cpp
    │   │   ├── StorageIntf.h
    │   │   ├── SysInitIntf.cpp
    │   │   ├── SysInitIntf.h
    │   │   ├── SystemIntf.cpp
    │   │   ├── SystemIntf.h
    │   │   ├── TARArchive.cpp
    │   │   ├── tar.h
    │   │   ├── TextStream.cpp
    │   │   ├── TextStream.h
    │   │   ├── UserEvent.h
    │   │   ├── UtilStreams.cpp
    │   │   ├── UtilStreams.h
    │   │   ├── win32
    │   │   │   ├── EventImpl.cpp
    │   │   │   ├── EventImpl.h
    │   │   │   ├── FileSelector.cpp
    │   │   │   ├── FileSelector.h
    │   │   │   ├── FuncStubs.cpp
    │   │   │   ├── FuncStubs.h
    │   │   │   ├── NativeEventQueue.cpp
    │   │   │   ├── NativeEventQueue.h
    │   │   │   ├── PluginImpl.cpp
    │   │   │   ├── PluginImpl.h
    │   │   │   ├── ScriptMgnImpl.cpp
    │   │   │   ├── ScriptMgnImpl.h
    │   │   │   ├── StorageImpl.cpp
    │   │   │   ├── StorageImpl.h
    │   │   │   ├── SusieArchive.cpp
    │   │   │   ├── SusieArchive.h
    │   │   │   ├── SysInitImpl.cpp
    │   │   │   ├── SysInitImpl.h
    │   │   │   ├── SystemImpl.cpp
    │   │   │   ├── SystemImpl.h
    │   │   │   └── win32io.h
    │   │   ├── XP3Archive.cpp
    │   │   ├── XP3Archive.h
    │   │   └── ZIPArchive.cpp
    │   ├── environ
    │   │   ├── android
    │   │   │   ├── AndroidUtils.cpp
    │   │   │   └── AndroidUtils.h
    │   │   ├── Application.cpp
    │   │   ├── Application.h
    │   │   ├── cocos2d
    │   │   │   ├── AppDelegate.cpp
    │   │   │   ├── AppDelegate.h
    │   │   │   ├── CCKeyCodeConv.cpp
    │   │   │   ├── CCKeyCodeConv.h
    │   │   │   ├── CustomFileUtils.cpp
    │   │   │   ├── CustomFileUtils.h
    │   │   │   ├── CustomFileUtils.mm
    │   │   │   ├── MainScene.cpp
    │   │   │   ├── MainScene.h
    │   │   │   ├── YUVSprite.cpp
    │   │   │   └── YUVSprite.h
    │   │   ├── combase.h
    │   │   ├── ConfigManager
    │   │   │   ├── GlobalConfigManager.cpp
    │   │   │   ├── GlobalConfigManager.h
    │   │   │   ├── IndividualConfigManager.cpp
    │   │   │   ├── IndividualConfigManager.h
    │   │   │   ├── LocaleConfigManager.cpp
    │   │   │   └── LocaleConfigManager.h
    │   │   ├── cpu_types.h
    │   │   ├── DetectCPU.cpp
    │   │   ├── DetectCPU.h
    │   │   ├── DumpSend.cpp
    │   │   ├── linux
    │   │   │   └── Platform.cpp
    │   │   ├── Platform.h
    │   │   ├── sdl
    │   │   │   └── tvpsdl.cpp
    │   │   ├── typedefine.h
    │   │   ├── ui
    │   │   │   ├── BaseForm.cpp
    │   │   │   ├── BaseForm.h
    │   │   │   ├── ConsoleWindow.cpp
    │   │   │   ├── ConsoleWindow.h
    │   │   │   ├── DebugViewLayerForm.cpp
    │   │   │   ├── DebugViewLayerForm.h
    │   │   │   ├── extension
    │   │   │   │   ├── ActionExtension.cpp
    │   │   │   │   ├── ActionExtension.h
    │   │   │   │   ├── UIExtension.cpp
    │   │   │   │   └── UIExtension.h
    │   │   │   ├── FileSelectorForm.cpp
    │   │   │   ├── FileSelectorForm.h
    │   │   │   ├── GameMainMenu.cpp
    │   │   │   ├── GameMainMenu.h
    │   │   │   ├── GlobalPreferenceForm.cpp
    │   │   │   ├── GlobalPreferenceForm.h
    │   │   │   ├── IndividualPreferenceForm.cpp
    │   │   │   ├── IndividualPreferenceForm.h
    │   │   │   ├── InGameMenuForm.cpp
    │   │   │   ├── InGameMenuForm.h
    │   │   │   ├── MainFileSelectorForm.cpp
    │   │   │   ├── MainFileSelectorForm.h
    │   │   │   ├── MessageBox.cpp
    │   │   │   ├── MessageBox.h
    │   │   │   ├── PreferenceConfig.h
    │   │   │   ├── PreferenceForm.cpp
    │   │   │   ├── PreferenceForm.h
    │   │   │   ├── SeletListForm.cpp
    │   │   │   ├── SeletListForm.h
    │   │   │   ├── SimpleMediaFilePlayer.cpp
    │   │   │   ├── SimpleMediaFilePlayer.h
    │   │   │   ├── TipsHelpForm.cpp
    │   │   │   ├── TipsHelpForm.h
    │   │   │   ├── XP3RepackForm.cpp
    │   │   │   └── XP3RepackForm.h
    │   │   ├── vkdefine.h
    │   │   ├── win32
    │   │   │   ├── ApplicationSpecialPath.h
    │   │   │   ├── CompatibleNativeFuncs.cpp
    │   │   │   ├── CompatibleNativeFuncs.h
    │   │   │   ├── ConfigFormUnit.cpp
    │   │   │   ├── ConfigFormUnit.h
    │   │   │   ├── config.h
    │   │   │   ├── DetectCPU.cpp
    │   │   │   ├── DetectCPU.h
    │   │   │   ├── EmergencyExit.cpp
    │   │   │   ├── EmergencyExit.h
    │   │   │   ├── HintWindow.cpp
    │   │   │   ├── HintWindow.h
    │   │   │   ├── ImeControl.h
    │   │   │   ├── MainFormUnit.cpp
    │   │   │   ├── MainFormUnit.h
    │   │   │   ├── MouseCursor.cpp
    │   │   │   ├── MouseCursor.h
    │   │   │   ├── my_HintWindow.cpp
    │   │   │   ├── Platform.cpp
    │   │   │   ├── SystemControl.cpp
    │   │   │   ├── SystemControl.h
    │   │   │   ├── TouchPoint.cpp
    │   │   │   ├── TouchPoint.h
    │   │   │   ├── TVPWindow.cpp
    │   │   │   ├── TVPWindow.h
    │   │   │   ├── VersionFormUnit.cpp
    │   │   │   ├── VersionFormUnit.h
    │   │   │   ├── WindowFormUnit.cpp
    │   │   │   ├── WindowFormUnit.h
    │   │   │   ├── WindowsUtil.cpp
    │   │   │   └── WindowsUtil.h
    │   │   ├── win32type.h
    │   │   ├── XP3ArchiveRepack.cpp
    │   │   └── XP3ArchiveRepack.h
    │   ├── extension
    │   │   ├── Extension.cpp
    │   │   └── Extension.h
    │   ├── movie
    │   │   ├── ffmpeg
    │   │   │   ├── AEAudioFormat.h
    │   │   │   ├── AEChannelData.h
    │   │   │   ├── AEChannelInfo.cpp
    │   │   │   ├── AEChannelInfo.h
    │   │   │   ├── AEFactory.cpp
    │   │   │   ├── AEFactory.h
    │   │   │   ├── AE.h
    │   │   │   ├── AEStreamData.h
    │   │   │   ├── AEStream.h
    │   │   │   ├── AEStreamInfo.cpp
    │   │   │   ├── AEStreamInfo.h
    │   │   │   ├── AEUtil.cpp
    │   │   │   ├── AEUtil.h
    │   │   │   ├── AudioCodecFFmpeg.cpp
    │   │   │   ├── AudioCodecFFmpeg.h
    │   │   │   ├── AudioCodec.h
    │   │   │   ├── AudioCodecPassthrough.cpp
    │   │   │   ├── AudioCodecPassthrough.h
    │   │   │   ├── AudioDevice.cpp
    │   │   │   ├── AudioDevice.h
    │   │   │   ├── BaseRenderer.cpp
    │   │   │   ├── BaseRenderer.h
    │   │   │   ├── BitstreamStats.cpp
    │   │   │   ├── BitstreamStats.h
    │   │   │   ├── Clock.cpp
    │   │   │   ├── Clock.h
    │   │   │   ├── Codecs.h
    │   │   │   ├── CodecUtils.cpp
    │   │   │   ├── CodecUtils.h
    │   │   │   ├── config.h
    │   │   │   ├── Demux.cpp
    │   │   │   ├── DemuxFFmpeg.cpp
    │   │   │   ├── DemuxFFmpeg.h
    │   │   │   ├── Demux.h
    │   │   │   ├── DemuxPacket.cpp
    │   │   │   ├── DemuxPacket.h
    │   │   │   ├── FactoryCodec.cpp
    │   │   │   ├── FactoryCodec.h
    │   │   │   ├── Geometry.h
    │   │   │   ├── IAudioCallback.h
    │   │   │   ├── InputStream.cpp
    │   │   │   ├── InputStream.h
    │   │   │   ├── IVideoPlayer.h
    │   │   │   ├── krffmpeg.cpp
    │   │   │   ├── KRMovieDef.h
    │   │   │   ├── KRMovieLayer.cpp
    │   │   │   ├── KRMovieLayer.h
    │   │   │   ├── KRMoviePlayer.cpp
    │   │   │   ├── KRMoviePlayer.h
    │   │   │   ├── MathUtils.h
    │   │   │   ├── Message.cpp
    │   │   │   ├── Message.h
    │   │   │   ├── MessageQueue.cpp
    │   │   │   ├── MessageQueue.h
    │   │   │   ├── OptionInfo.h
    │   │   │   ├── ProcessInfo.cpp
    │   │   │   ├── ProcessInfo.h
    │   │   │   ├── Ref.h
    │   │   │   ├── RenderFlags.cpp
    │   │   │   ├── RenderFlags.h
    │   │   │   ├── RenderFormats.h
    │   │   │   ├── StreamInfo.cpp
    │   │   │   ├── StreamInfo.h
    │   │   │   ├── Thread.cpp
    │   │   │   ├── Thread.h
    │   │   │   ├── Timer.cpp
    │   │   │   ├── Timer.h
    │   │   │   ├── TimeUtils.cpp
    │   │   │   ├── TimeUtils.h
    │   │   │   ├── TVPMediaDemux.cpp
    │   │   │   ├── TVPMediaDemux.h
    │   │   │   ├── VideoCodec.cpp
    │   │   │   ├── VideoCodecFFmpeg.cpp
    │   │   │   ├── VideoCodecFFmpeg.h
    │   │   │   ├── VideoCodec.h
    │   │   │   ├── VideoPlayerAudio.cpp
    │   │   │   ├── VideoPlayerAudio.h
    │   │   │   ├── VideoPlayer.cpp
    │   │   │   ├── VideoPlayer.h
    │   │   │   ├── VideoPlayerVideo.cpp
    │   │   │   ├── VideoPlayerVideo.h
    │   │   │   ├── VideoReferenceClock.cpp
    │   │   │   ├── VideoReferenceClock.h
    │   │   │   ├── VideoRenderer.cpp
    │   │   │   └── VideoRenderer.h
    │   │   └── krmovie.cpp
    │   ├── msg
    │   │   ├── MsgIntf.cpp
    │   │   ├── MsgIntf.h
    │   │   ├── MsgIntfInc.h
    │   │   └── win32
    │   │       ├── MsgImpl.cpp
    │   │       ├── MsgImpl.h
    │   │       ├── MsgLoad.cpp
    │   │       ├── OptionsDesc.cpp
    │   │       ├── OptionsDesc.h
    │   │       ├── ReadOptionDesc.cpp
    │   │       └── ReadOptionDesc.h
    │   ├── sound
    │   │   ├── ARM
    │   │   │   ├── WaveFunctionARM.cpp
    │   │   │   └── wavemix_arm.c
    │   │   ├── CDDAIntf.cpp
    │   │   ├── CDDAIntf.h
    │   │   ├── FFWaveDecoder.cpp
    │   │   ├── FFWaveDecoder.h
    │   │   ├── MathAlgorithms.cpp
    │   │   ├── MathAlgorithms.h
    │   │   ├── MIDIIntf.cpp
    │   │   ├── MIDIIntf.h
    │   │   ├── PhaseVocoderDSP.cpp
    │   │   ├── PhaseVocoderDSP.h
    │   │   ├── PhaseVocoderFilter.cpp
    │   │   ├── PhaseVocoderFilter.h
    │   │   ├── RingBuffer.h
    │   │   ├── SoundBufferBaseIntf.cpp
    │   │   ├── SoundBufferBaseIntf.h
    │   │   ├── VorbisWaveDecoder.cpp
    │   │   ├── VorbisWaveDecoder.h
    │   │   ├── WaveFormatConverter.cpp
    │   │   ├── WaveFormatConverter_SSE.cpp
    │   │   ├── WaveIntf.cpp
    │   │   ├── WaveIntf.h
    │   │   ├── WaveLoopManager.cpp
    │   │   ├── WaveLoopManager.h
    │   │   ├── WaveSegmentQueue.cpp
    │   │   ├── WaveSegmentQueue.h
    │   │   └── win32
    │   │       ├── CDDAImpl.cpp
    │   │       ├── CDDAImpl.h
    │   │       ├── kmp_pi.h
    │   │       ├── MIDIImpl.cpp
    │   │       ├── MIDIImpl.h
    │   │       ├── oldwaveunpacker.h
    │   │       ├── SoundBufferBaseImpl.cpp
    │   │       ├── SoundBufferBaseImpl.h
    │   │       ├── tvpsnd.c
    │   │       ├── tvpsnd.cpp
    │   │       ├── tvpsnd.h
    │   │       ├── tvpsnd.idl
    │   │       ├── WaveImpl.cpp
    │   │       ├── WaveImpl.h
    │   │       ├── WaveMixer.cpp
    │   │       └── WaveMixer.h
    │   ├── tjs2
    │   │   ├── tjsArray.cpp
    │   │   ├── tjsArray.h
    │   │   ├── tjsBinarySerializer.cpp
    │   │   ├── tjsBinarySerializer.h
    │   │   ├── tjsByteCodeLoader.cpp
    │   │   ├── tjsByteCodeLoader.h
    │   │   ├── tjsCommHead.h
    │   │   ├── tjsCompileControl.cpp
    │   │   ├── tjsCompileControl.h
    │   │   ├── tjsConfig.cpp
    │   │   ├── tjsConfig.h
    │   │   ├── tjsConstArrayData.cpp
    │   │   ├── tjsConstArrayData.h
    │   │   ├── tjs.cpp
    │   │   ├── tjsDate.cpp
    │   │   ├── tjsDate.h
    │   │   ├── tjsDateParser.cpp
    │   │   ├── tjsDateParser.h
    │   │   ├── tjsdate.tab.cpp
    │   │   ├── tjsdate.tab.h
    │   │   ├── tjsdate.tab.hpp
    │   │   ├── tjsDateWordMap.cc
    │   │   ├── tjsDebug.cpp
    │   │   ├── tjsDebug.h
    │   │   ├── tjsDictionary.cpp
    │   │   ├── tjsDictionary.h
    │   │   ├── tjsDisassemble.cpp
    │   │   ├── tjsError.cpp
    │   │   ├── tjsErrorDefs.h
    │   │   ├── tjsError.h
    │   │   ├── tjsErrorInc.h
    │   │   ├── tjsError_jp.h
    │   │   ├── tjsException.cpp
    │   │   ├── tjsException.h
    │   │   ├── tjsGlobalStringMap.cpp
    │   │   ├── tjsGlobalStringMap.h
    │   │   ├── tjs.h
    │   │   ├── tjsHashSearch.h
    │   │   ├── tjsInterCodeExec.cpp
    │   │   ├── tjsInterCodeExec.h
    │   │   ├── tjsInterCodeGen.cpp
    │   │   ├── tjsInterCodeGen.h
    │   │   ├── tjsInterface.cpp
    │   │   ├── tjsInterface.h
    │   │   ├── tjsLex.cpp
    │   │   ├── tjsLex.h
    │   │   ├── tjsMath.cpp
    │   │   ├── tjsMath.h
    │   │   ├── tjsMessage.cpp
    │   │   ├── tjsMessage.h
    │   │   ├── tjsMT19937ar-cok.cpp
    │   │   ├── tjsMT19937ar-cok.h
    │   │   ├── tjsNamespace.cpp
    │   │   ├── tjsNamespace.h
    │   │   ├── tjsNative.cpp
    │   │   ├── tjsNative.h
    │   │   ├── tjsObject.cpp
    │   │   ├── tjsObjectExtendable.cpp
    │   │   ├── tjsObjectExtendable.h
    │   │   ├── tjsObject.h
    │   │   ├── tjsOctPack.cpp
    │   │   ├── tjsOctPack.h
    │   │   ├── tjspp.tab.cpp
    │   │   ├── tjspp.tab.hpp
    │   │   ├── tjsRandomGenerator.cpp
    │   │   ├── tjsRandomGenerator.h
    │   │   ├── tjsRegExp.cpp
    │   │   ├── tjsRegExp.h
    │   │   ├── tjsScriptBlock.cpp
    │   │   ├── tjsScriptBlock.h
    │   │   ├── tjsScriptCache.cpp
    │   │   ├── tjsScriptCache.h
    │   │   ├── tjsString.cpp
    │   │   ├── tjsString.h
    │   │   ├── tjs.tab.cpp
    │   │   ├── tjs.tab.h
    │   │   ├── tjs.tab.hpp
    │   │   ├── tjsTypes.h
    │   │   ├── tjsUtils.cpp
    │   │   ├── tjsUtils.h
    │   │   ├── tjsVariant.cpp
    │   │   ├── tjsVariant.h
    │   │   ├── tjsVariantString.cpp
    │   │   └── tjsVariantString.h
    │   ├── utils
    │   │   ├── ClipboardIntf.cpp
    │   │   ├── ClipboardIntf.h
    │   │   ├── Debugger.h
    │   │   ├── DebugIntf.cpp
    │   │   ├── DebugIntf.h
    │   │   ├── encoding
    │   │   │   ├── gbk2unicode.c
    │   │   │   └── jis2unicode.c
    │   │   ├── Exception.h
    │   │   ├── FilePathUtil.h
    │   │   ├── iconv
    │   │   │   ├── iconv.h
    │   │   │   └── utf8.h
    │   │   ├── KAGParser.cpp
    │   │   ├── KAGParser.h
    │   │   ├── MathAlgorithms_Default.cpp
    │   │   ├── MathAlgorithms_Default.h
    │   │   ├── MathAlgorithms.h
    │   │   ├── md5.c
    │   │   ├── md5.h
    │   │   ├── minizip
    │   │   │   ├── crypt.h
    │   │   │   ├── ioapi.cpp
    │   │   │   ├── ioapi.h
    │   │   │   ├── unzip.c
    │   │   │   ├── unzip.h
    │   │   │   ├── zip.c
    │   │   │   └── zip.h
    │   │   ├── MiscUtility.cpp
    │   │   ├── ObjectList.h
    │   │   ├── PadIntf.cpp
    │   │   ├── PadIntf.h
    │   │   ├── Random.cpp
    │   │   ├── Random.h
    │   │   ├── RealFFT_Default.cpp
    │   │   ├── RealFFT.h
    │   │   ├── StringUtil.h
    │   │   ├── ThreadIntf.cpp
    │   │   ├── ThreadIntf.h
    │   │   ├── TickCount.cpp
    │   │   ├── TickCount.h
    │   │   ├── TimerIntf.cpp
    │   │   ├── TimerIntf.h
    │   │   ├── VelocityTracker.cpp
    │   │   ├── VelocityTracker.h
    │   │   └── win32
    │   │       ├── ClipboardImpl.cpp
    │   │       ├── ClipboardImpl.h
    │   │       ├── DebugImpl.cpp
    │   │       ├── DebugImpl.h
    │   │       ├── PadImpl.cpp
    │   │       ├── PadImpl.h
    │   │       ├── ThreadImpl.cpp
    │   │       ├── ThreadImpl.h
    │   │       ├── TimerImpl.cpp
    │   │       ├── TimerImpl.h
    │   │       ├── TVPTimer.cpp
    │   │       └── TVPTimer.h
    │   └── visual
    │       ├── argb.cpp
    │       ├── argb.h
    │       ├── ARM
    │       │   ├── AlphaMovie_mjpeg.h
    │       │   ├── tvpgl_arm.cpp
    │       │   └── tvpgl_arm_intf.h
    │       ├── BitmapIntf.cpp
    │       ├── BitmapIntf.h
    │       ├── BitmapLayerTreeOwner.cpp
    │       ├── BitmapLayerTreeOwner.h
    │       ├── CharacterData.cpp
    │       ├── CharacterData.h
    │       ├── ComplexRect.cpp
    │       ├── ComplexRect.h
    │       ├── drawable.h
    │       ├── FontImpl.cpp
    │       ├── FontImpl.h
    │       ├── FontRasterizer.h
    │       ├── FontSystem.cpp
    │       ├── FontSystem.h
    │       ├── FreeType.cpp
    │       ├── FreeTypeFace.h
    │       ├── FreeTypeFontRasterizer.cpp
    │       ├── FreeTypeFontRasterizer.h
    │       ├── FreeType.h
    │       ├── gl
    │       │   ├── blend_function.cpp
    │       │   ├── blend_functor_c.h
    │       │   ├── blend_util_func.h
    │       │   ├── blend_variation.h
    │       │   ├── ResampleImage.cpp
    │       │   ├── ResampleImage.h
    │       │   ├── ResampleImageInternal.h
    │       │   ├── tvpgl_mathutil.h
    │       │   ├── WeightFunctor.cpp
    │       │   └── WeightFunctor.h
    │       ├── GraphicsLoaderIntf.cpp
    │       ├── GraphicsLoaderIntf.h
    │       ├── GraphicsLoadThread.cpp
    │       ├── GraphicsLoadThread.h
    │       ├── ImageFunction.cpp
    │       ├── ImageFunction.h
    │       ├── LayerBitmapIntf.cpp
    │       ├── LayerBitmapIntf.h
    │       ├── LayerIntf.cpp
    │       ├── LayerIntf.h
    │       ├── LayerManager.cpp
    │       ├── LayerManager.h
    │       ├── LayerTreeOwner.h
    │       ├── LayerTreeOwnerImpl.cpp
    │       ├── LayerTreeOwnerImpl.h
    │       ├── LoadBPG.cpp
    │       ├── LoadJPEG.cpp
    │       ├── LoadJXR.cpp
    │       ├── LoadPNG.cpp
    │       ├── LoadPVRv3.cpp
    │       ├── LoadTLG.cpp
    │       ├── LoadTLG.h
    │       ├── LoadWEBP.cpp
    │       ├── MenuItemIntf.cpp
    │       ├── MenuItemIntf.h
    │       ├── ogl
    │       │   ├── astcrt.cpp
    │       │   ├── astcrt.h
    │       │   ├── etcpak.cpp
    │       │   ├── etcpak.h
    │       │   ├── imagepacker.cpp
    │       │   ├── imagepacker.h
    │       │   ├── ogl_common.h
    │       │   ├── pvr.h
    │       │   ├── pvrtc.cpp
    │       │   ├── pvrtc.h
    │       │   ├── RenderManager_ogl.cpp
    │       │   └── RenderManager_ogl_test.hpp
    │       ├── PrerenderedFont.cpp
    │       ├── PrerenderedFont.h
    │       ├── RectItf.cpp
    │       ├── RectItf.h
    │       ├── RenderManager.cpp
    │       ├── RenderManager.h
    │       ├── RenderManager_software.h
    │       ├── SaveTLG5.cpp
    │       ├── SaveTLG6.cpp
    │       ├── SaveTLG.h
    │       ├── transhandler.h
    │       ├── TransIntf.cpp
    │       ├── TransIntf.h
    │       ├── tvpfontstruc.h
    │       ├── tvpgl_asm_init.h
    │       ├── tvpgl.cpp
    │       ├── tvpgl.h
    │       ├── tvphal.h
    │       ├── tvpinputdefs.h
    │       ├── tvpps.inc
    │       ├── VideoOvlIntf.cpp
    │       ├── VideoOvlIntf.h
    │       ├── voMode.h
    │       ├── win32
    │       │   ├── BasicDrawDevice.cpp
    │       │   ├── BasicDrawDevice.h
    │       │   ├── BitmapBitsAlloc.cpp
    │       │   ├── BitmapBitsAlloc.h
    │       │   ├── BitmapInfomation.cpp
    │       │   ├── BitmapInfomation.h
    │       │   ├── DInputMgn.cpp
    │       │   ├── DInputMgn.h
    │       │   ├── DrawDevice.cpp
    │       │   ├── DrawDevice.h
    │       │   ├── GDIFontRasterizer.cpp
    │       │   ├── GDIFontRasterizer.h
    │       │   ├── GraphicsLoaderImpl.cpp
    │       │   ├── GraphicsLoaderImpl.h
    │       │   ├── krmovie.h
    │       │   ├── LayerBitmapImpl.cpp
    │       │   ├── LayerBitmapImpl.h
    │       │   ├── LayerImpl.cpp
    │       │   ├── LayerImpl.h
    │       │   ├── MenuItemImpl.cpp
    │       │   ├── MenuItemImpl.h
    │       │   ├── NativeFreeTypeFace.cpp
    │       │   ├── NativeFreeTypeFace.h
    │       │   ├── PassThroughDrawDevice.cpp
    │       │   ├── PassThroughDrawDevice.h
    │       │   ├── TVPColor.h
    │       │   ├── TVPScreen.cpp
    │       │   ├── TVPScreen.h
    │       │   ├── TVPSysFont.cpp
    │       │   ├── TVPSysFont.h
    │       │   ├── VideoOvlImpl.cpp
    │       │   ├── VideoOvlImpl.h
    │       │   ├── VSyncTimingThread.cpp
    │       │   ├── VSyncTimingThread.h
    │       │   ├── WindowImpl.cpp
    │       │   └── WindowImpl.h
    │       ├── WindowIntf.cpp
    │       └── WindowIntf.h
    └── plugins
        ├── addFont.cpp
        ├── Android.mk
        ├── csvParser.cpp
        ├── dirlist.cpp
        ├── fftgraph.cpp
        ├── getabout.cpp
        ├── getSample.cpp
        ├── InternalPlugins.cpp
        ├── LayerExBase.cpp
        ├── LayerExBase.h
        ├── layerExBase.hpp
        ├── layerExMovie.cpp
        ├── layerExPerspective.cpp
        ├── ncbind
        │   ├── ncb_foreach.h
        │   ├── ncbind.cpp
        │   ├── ncbind.hpp
        │   └── ncb_invoke.hpp
        ├── PluginStub.h
        ├── saveStruct.cpp
        ├── tp_stub.h
        ├── varfile.cpp
        ├── win32dialog.cpp
        ├── wutcwf.cpp
        ├── xp3filter.cpp
        └── xp3filter.h

```

## Engineer
### COCOS2D

- Know: Cocos2d-objc, Cocos2d-x, Cocos2d-html5 and Cocos2d-XNA



