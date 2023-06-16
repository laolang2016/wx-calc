#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys 
import os
from shutil import copyfile

app_name = 'wx_calc'
test_name = ''


if __name__ == "__main__":
    dll_path = sys.argv[1]
    dll_name = sys.argv[2]
    platform = sys.argv[3]
    configuration = sys.argv[4]
    proj_dir = sys.argv[5]

    if 'Debug' == configuration:
        dll_name = dll_name + 'd'

    # print('dll_path:',dll_path)
    # print('dll_name:',dll_name)
    # print('platform:',platform)
    # print('configuration:',configuration)
    # print('proj_dir:',proj_dir)
    # print('app_name:',app_name)
    # print('===================')

    build_path = proj_dir + os.path.sep + 'out' + os.path.sep + 'build'
    if 'x64' == platform:
        build_path = build_path + os.path.sep + 'x64'
    else:
        build_path = build_path + os.path.sep + 'x86'
    if 'Debug' == configuration:
        build_path = build_path + '-debug'
    else:
        build_path = build_path + '-release'
    app_path = build_path + os.path.sep + 'src' + os.path.sep + app_name
    test_path = build_path + os.path.sep + 'test'

    # print('app_path:',app_path)
    # print('test_path:',test_path)
    # print('dll_path:',dll_path)
    # print('dll_name:',dll_name)
    # print('===================')

    source_dll = dll_path + os.path.sep + dll_name + '.dll'
    target_app_dll = app_path + os.path.sep + dll_name + '.dll'
    target_test_dll = test_path + os.path.sep + dll_name + '.dll'

    # print('source_dll:',source_dll)
    # print('target_app_dll:',target_app_dll)
    # print('target_test_dll:',target_test_dll)

    # 复制到 app 目录
    print(source_dll + ' => ' + target_app_dll)
    if not os.path.exists(target_app_dll):
        copyfile(source_dll, target_app_dll)
    # 复制到 test 目录
    print(source_dll + ' => ' + target_test_dll)
    if not os.path.exists(target_test_dll):
        copyfile(source_dll, target_test_dll)
