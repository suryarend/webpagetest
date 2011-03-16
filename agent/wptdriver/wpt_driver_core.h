#pragma once
#include "ipfw.h"


class WptDriverCore
{
public:
  WptDriverCore(WptStatus &status);
  ~WptDriverCore(void);

  void Start(void);
  void Stop(void);
  void WorkThread(void);
  void MessageThread(void);
  bool OnMessage(UINT message);

private:
  WptSettings _settings;
  WptHook     _hook;
  WptStatus&  _status;
  WebPagetest _webpagetest;
  WebBrowser *_browser;
  CWinPCap winpcap;
  CIpfw       _ipfw;
  bool        _exit;
  HANDLE      _work_thread;
  HANDLE      _message_thread;
  HWND        _message_window;
  TestServer  _test_server;
  CRITICAL_SECTION  cs;
  HANDLE      _testing_mutex;

  bool ConfigureIpfw(WptTest& test);
  void ResetIpfw(void);
  void Init(void);
  void FlushDNS(void);
};

