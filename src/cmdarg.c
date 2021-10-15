#include "cgraph_base.h"
#include "cgraph_cmdarg.h"

static cgraph_size_t cgraph_cmdarg_memlen(int argc, char *argv[]);

cgraph_size_t cgraph_cmdarg_memlen(int argc, char *argv[]) {
  cgraph_size_t i = 0, len = argc + 1;
  for (; i < argc; i++) {
    len += cgraph_strlen(argv[i]);
  }

  return len;
}

cgraph_cmdarg_t *cgraph_cmdarg_calloc(int argc, char *argv[]) {
  cgraph_cmdarg_t *cmdarg =
      (cgraph_cmdarg_t *)cgraph_calloc(sizeof(cgraph_cmdarg_t));
  if (NULL != cmdarg) {
    if (NULL !=
        (cmdarg->args = cgraph_calloc(argc * sizeof(cgraph_char_t *)))) {
      cgraph_size_t len = cgraph_cmdarg_memlen(argc, argv);
      if (NULL != (cmdarg->data = cgraph_calloc(len * sizeof(cgraph_char_t)))) {
        cgraph_size_t i = 0, j, k = 0;
        cmdarg->name = cmdarg->data;
        cmdarg->len = argc - 1;
        for (; i < argc; i++) {
          for (j = 0; '\0' != argv[i][j]; j++) {
            cmdarg->data[k++] = argv[i][j];
          }
          cmdarg->data[k++] = '\0';
          cmdarg->args[i] = &(cmdarg->data[k]);
        }
      } else {
        cgraph_free(cmdarg->args);
        cgraph_free(cmdarg);
      }
    } else {
      cgraph_free(cmdarg);
    }
  }

  return cmdarg;
}

void cgraph_cmdarg_free(cgraph_cmdarg_t *cthis) {
  if (NULL != cthis) {
    cgraph_free(cthis->args);
    cgraph_free(cthis->data);
    cgraph_free(cthis);
  }
}

cgraph_char_t *cgraph_cmdarg_nam(const cgraph_cmdarg_t *cthis) {
  return ((NULL != cthis) ? cthis->name : NULL);
}

cgraph_size_t cgraph_cmdarg_namlen(const cgraph_cmdarg_t *cthis) {
  return ((NULL != cthis) ? (cthis->args[0] - cthis->name) : 0);
}

cgraph_bool_t cgraph_cmdarg_isarg(const cgraph_cmdarg_t *cthis,
                                  const cgraph_char_t *arg) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && (NULL != arg)) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (cgraph_strcmp(cthis->args[i], arg)) {
        flag = CGRAPH_TRUE;
        break;
      }
    }
  }

  return flag;
}

cgraph_size_t cgraph_cmdarg_argnum(const cgraph_cmdarg_t *cthis,
                                   const cgraph_char_t *arg) {
  cgraph_size_t num = -1;
  if ((NULL != cthis) && (NULL != arg)) {
    cgraph_size_t i = 0;
    for (; i < cthis->len; i++) {
      if (cgraph_strcmp(cthis->args[i], arg)) {
        num = i;
        break;
      }
    }
  }

  return num;
}

cgraph_char_t *cgraph_cmdarg_argnam(const cgraph_cmdarg_t *cthis,
                                    const cgraph_size_t argnum) {
  return (((NULL != cthis) && (argnum < cthis->len) && (0 <= argnum))
              ? cthis->args[argnum]
              : NULL);
}

cgraph_size_t cgraph_cmdarg_arglen(const cgraph_cmdarg_t *cthis,
                                   const cgraph_size_t argnum) {
  return (((NULL != cthis) && (argnum < cthis->len) && (0 <= argnum))
              ? (cthis->args[argnum + 1] - cthis->args[argnum] - 1)
              : 0);
}

cgraph_size_t cgraph_cmdarg_fprintln(FILE *fp, const cgraph_cmdarg_t *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    len += cgraph_file_fprintfln(fp, "program : %s", cthis->name);
    for (; i < cthis->len; i++) {
      len += cgraph_file_fprintfln(fp, "command %ld : %s", i, cthis->args[i]);
    }
  }

  return len;
}
