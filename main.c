#include <stddef.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
#include "system.h"
#include <regex.h>
#include <rpm/rpmcli.h>
#include <rpm/rpmfileutil.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmlog.h>
#include <rpm/rpmmacro.h>
#include <rpm/rpmstring.h>
#include <rpm/rpmtypes.h>
#define true 1
#define false 0
#define BUFMAX 131072

// int setenv(const char *name, const char *value, int overwrite);
// char *rpmExpand(const char *arg, ...) RPM_GNUC_NULL_TERMINATED;
// int rpmReadConfigFiles(const char *file, const char *target);
// const char *rpmcliRc = "/usr/lib/rpm/clr/rpmrc";

static int rpmcliInitialized = -1;

regex_t **compRegex(const char *pattern, regex_t **regexList,
                    int *regexListSize) {

  regexList = xcalloc(1, (sizeof(*regexList) * 1));
  *regexListSize = 1;
  printf("1 (regexListSize - 1): (%d -1): %d\n", *regexListSize,
         (*regexListSize - 1));
  regexList[(*regexListSize - 1)] = xcalloc(1, sizeof(**regexList));
  printf("1 regexList[0]: %p\n", regexList[0]);
  regcomp(regexList[(*regexListSize - 1)], "/aot/intel/oneapi", REG_EXTENDED);
  printf("1 regexListSize: %d\n", *regexListSize);

  *regexListSize = (*regexListSize + 1);
  printf("2 (regexListSize - 1): (%d -1): %d\n", *regexListSize,
         (*regexListSize - 1));
  regexList = xrealloc(regexList, (sizeof(*regexList) * *regexListSize));

  regexList[(*regexListSize - 1)] = xcalloc(1, sizeof(**regexList));
  regcomp(regexList[(*regexListSize - 1)], "/usr/nvidia", REG_EXTENDED);
  printf("2 regexList[0]: %p\n", regexList[0]);
  printf("2 regexList[1]: %p\n", regexList[1]);
  printf("2 regexListSize: %d\n", *regexListSize);

  *regexListSize = (*regexListSize + 1);
  printf("3 (regexListSize - 1): (%d -1): %d\n", *regexListSize,
         (*regexListSize - 1));
  regexList = xrealloc(regexList, (sizeof(*regexList) * *regexListSize));

  regexList[(*regexListSize - 1)] = xcalloc(1, sizeof(**regexList));
  regcomp(regexList[(*regexListSize - 1)], "/usr/local/cuda", REG_EXTENDED);
  printf("3 regexList[0]: %p\n", regexList[0]);
  printf("3 regexList[1]: %p\n", regexList[1]);
  printf("3 regexList[2]: %p\n", regexList[2]);
  printf("3 regexListSize: %d\n", *regexListSize);

  return regexList;
}

int main(int argc, char **argv) {
  //  int test = (1 && false == 0);
  //  printf("test: %d\n", test);
  //  if (test == 0) {
  //    printf("ok\n");
  //  } else {
  //    printf("not\n");
  //  }

  //  orderedIds = malloc(variableNumberOfElements * sizeof(char*));
  //  for (int i = 0; i < variableNumberOfElements; i++)
  //    orderedIds[i] = malloc((ID_LEN+1) * sizeof(char)); // yeah, I know
  //    sizeof(char) is 1, but to make it clear...

  rpmcliInitialized = rpmReadConfigFiles(NULL, NULL);
  regex_t **regexList;
  int regexListSize = 0;
  //  regexList = xcalloc(1, (sizeof(*regexList) * 1));
  //  regexListSize = 1;
  //  printf("1 (regexListSize - 1): (%d -1): %d\n", regexListSize,
  //         (regexListSize - 1));
  //  regexList[(regexListSize - 1)] = xcalloc(1, sizeof(**regexList));
  //  printf("1 regexList[0]: %p\n", regexList[0]);
  //  regcomp(regexList[(regexListSize - 1)], "/aot/intel/oneapi",
  //  REG_EXTENDED); printf("1 regexListSize: %d\n", regexListSize);

  //  regexListSize = (regexListSize + 1);
  //  printf("2 (regexListSize - 1): (%d -1): %d\n", regexListSize,
  //         (regexListSize - 1));
  //  regexList = xrealloc(regexList, (sizeof(*regexList) * regexListSize));

  //  regexList[(regexListSize - 1)] = xcalloc(1, sizeof(**regexList));
  //  regcomp(regexList[(regexListSize - 1)], "/usr/nvidia", REG_EXTENDED);
  //  printf("2 regexList[0]: %p\n", regexList[0]);
  //  printf("2 regexList[1]: %p\n", regexList[1]);
  //  printf("2 regexListSize: %d\n", regexListSize);

  //  regexListSize = (regexListSize + 1);
  //  printf("3 (regexListSize - 1): (%d -1): %d\n", regexListSize,
  //         (regexListSize - 1));
  //  regexList = xrealloc(regexList, (sizeof(*regexList) * regexListSize));

  //  regexList[(regexListSize - 1)] = xcalloc(1, sizeof(**regexList));
  //  regcomp(regexList[(regexListSize - 1)], "/usr/local/cuda", REG_EXTENDED);
  //  printf("3 regexList[0]: %p\n", regexList[0]);
  //  printf("3 regexList[1]: %p\n", regexList[1]);
  //  printf("3 regexList[2]: %p\n", regexList[2]);
  //  printf("3 regexListSize: %d\n", regexListSize);

  //  if (regexec(regexList[0], "/aot/intel/oneapi", 0, NULL, 0) == 0) {
  //    printf("Matched:\n");
  //  } else {
  //    printf("Not matched:\n");
  //  }
  //  if (regexec(regexList[1], "/aot/intel/oneapi", 0, NULL, 0) == 0) {
  //    printf("Matched:\n");
  //  } else {
  //    printf("Not matched:\n");
  //  }
  //  if (regexec(regexList[1], "/usr/nvidia", 0, NULL, 0) == 0) {
  //    printf("Matched:\n");
  //  } else {
  //    printf("Not matched:\n");
  //  }

  //  if (regexec(regexList[2], "/usr/local/cuda", 0, NULL, 0) == 0) {
  //    printf("Matched:\n");
  //  } else {
  //    printf("Not matched:\n");
  //  }
  //  if (regexec(regexList[2], "/usr/local/oi", 0, NULL, 0) == 0) {
  //    printf("Matched:\n");
  //  } else {
  //    printf("Not matched:\n");
  //  }

  //  regfree(regexList[0]);
  //  regfree(regexList[1]);
  //  regfree(regexList[2]);
  //  _free(regexList[0]);
  //  _free(regexList[1]);
  //  _free(regexList[2]);
  //  _free(regexList);
  //  rpmFreeRpmrc();

  for (int i = 1;; ++i) {
    char *macro = NULL;
    rasprintf(&macro, "%%__requires_exclude%d", i);
    //    fprintf(stdout, "%s\n", macro);
    char *val = NULL;
    rpmExpandMacros(NULL, macro, &val, 0);
    //    fprintf(stdout, "%s\n", val);
    if (strcmp(macro, val) != 0) {
      fprintf(stdout, "%s\n", val);
      // compRegex(val, regexList, &regexListSize);
      val = _free(val);
      macro = _free(macro);

    } else {
      val = _free(val);
      macro = _free(macro);
      break;
    }
  }
  regexList = compRegex("/aot/intel/oneapi", regexList, &regexListSize);
  printf("regexListSize: %d\n", regexListSize);

  if (regexec(regexList[0], "/aot/intel/oneapi", 0, NULL, 0) == 0) {
    printf("Matched:\n");
  } else {
    printf("Not matched:\n");
  }
  if (regexec(regexList[1], "/aot/intel/oneapi", 0, NULL, 0) == 0) {
    printf("Matched:\n");
  } else {
    printf("Not matched:\n");
  }
  if (regexec(regexList[1], "/usr/nvidia", 0, NULL, 0) == 0) {
    printf("Matched:\n");
  } else {
    printf("Not matched:\n");
  }

  if (regexec(regexList[2], "/usr/local/cuda", 0, NULL, 0) == 0) {
    printf("Matched:\n");
  } else {
    printf("Not matched:\n");
  }
  if (regexec(regexList[2], "/usr/local/oi", 0, NULL, 0) == 0) {
    printf("Matched:\n");
  } else {
    printf("Not matched:\n");
  }

  regfree(regexList[0]);
  regfree(regexList[1]);
  regfree(regexList[2]);
  _free(regexList[0]);
  _free(regexList[1]);
  _free(regexList[2]);
  _free(regexList);
  rpmFreeRpmrc();

  //  FILE *ldd;
  //  char path[PATH_MAX];

  //  ldd = popen("ldd /usr/lib64/libonemkl.so.0", "r");
  //  if (ldd != NULL) {
  //    while (fgets(path, PATH_MAX, ldd)) {
  //      //      if (regexec(regexList[1], path, 0, NULL, 0) == 0) {
  //      //        printf("Matched:\n");
  //      //      } else {
  //      //        printf("Not matched:\n");
  //      //      }
  //      printf("%s", path);
  //    }
  //  }
  //  (void)pclose(ldd);
}
//  char *val = NULL;
//  rpmExpandMacros(NULL, "%__requires_exclude1", &val, 0);
//  fprintf(stdout, "%s\n", val);
//  val = _free(val);
