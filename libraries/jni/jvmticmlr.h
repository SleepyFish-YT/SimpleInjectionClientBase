/*
 * Copyright (c) 2004, 2012, Oracle and/or its affiliates. All rights reserved.
 * ORACLE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#ifndef _JVMTI_CMLR_H_
#define _JVMTI_CMLR_H_

enum {
    JVMTI_CMLR_MAJOR_VERSION_1 = 0x00000001,
    JVMTI_CMLR_MINOR_VERSION_0 = 0x00000000,
    JVMTI_CMLR_MAJOR_VERSION   = 0x00000001,
    JVMTI_CMLR_MINOR_VERSION   = 0x00000000
};

#include "jni.h"

typedef enum {
    JVMTI_CMLR_DUMMY       = 1,
    JVMTI_CMLR_INLINE_INFO = 2
} jvmtiCMLRKind;

typedef struct _jvmtiCompiledMethodLoadRecordHeader {
  jvmtiCMLRKind kind;
  jint majorinfoversion;
  jint minorinfoversion;

  struct _jvmtiCompiledMethodLoadRecordHeader* next;
} jvmtiCompiledMethodLoadRecordHeader;

typedef struct _PCStackInfo {
  void* pc;
  jint numstackframes;
  jmethodID* methods;
  jint* bcis;
} PCStackInfo;

typedef struct _jvmtiCompiledMethodLoadInlineRecord {
  jvmtiCompiledMethodLoadRecordHeader header;
  jint numpcs;
  PCStackInfo* pcinfo;
} jvmtiCompiledMethodLoadInlineRecord;

typedef struct _jvmtiCompiledMethodLoadDummyRecord {
  jvmtiCompiledMethodLoadRecordHeader header;
  char message[50];
} jvmtiCompiledMethodLoadDummyRecord;

#endif