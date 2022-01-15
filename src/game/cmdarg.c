#include "cgraph_base.h"
#include "cgraph_cmdarg.h"

static cgraph_size_t cgraph_cmdarg_memlen(int argc, char *argv[]);

cgraph_size_t cgraph_cmdarg_memlen(int argc, char *argv[]) {
  cgraph_size_t len = argc + 1;
  CGRAPH_LOOP(i, 0, argc)
  len += cgraph_strlen(argv[i]);
  CGRAPH_LOOP_END

  return len;
}

cgraph_cmdarg_t *cgraph_cmdarg_calloc(int argc, char *argv[]) {
  cgraph_cmdarg_t *cmdarg =
      (cgraph_cmdarg_t *)cgraph_calloc(sizeof(cgraph_cmdarg_t));
  if (NULL != cmdarg) {
    if (NULL !=
        (cmdarg->argv = cgraph_calloc(argc * sizeof(cgraph_char_t *)))) {
      cmdarg->size = cgraph_cmdarg_memlen(argc, argv);
      if (NULL != (cmdarg->data =
                       cgraph_calloc(cmdarg->size * sizeof(cgraph_char_t)))) {
        cgraph_size_t j, k = 0;
        cmdarg->name = cmdarg->data;
        CGRAPH_LOOP(i, 0, argc)
        for (j = 0; '\0' != argv[i][j]; j++) {
          cmdarg->data[k++] = argv[i][j];
        }
        cmdarg->data[k++] = '\0';
        cmdarg->argv[i] = &(cmdarg->data[k]);
        CGRAPH_LOOP_END
        cmdarg->argc = argc - 1;
      } else {
        cgraph_free(cmdarg->argv);
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
    cgraph_free(cthis->argv);
    cgraph_free(cthis->data);
    cgraph_free(cthis);
  }
}

cgraph_char_t *cgraph_cmdarg_nam(const cgraph_cmdarg_t *cthis) {
  return ((NULL != cthis) ? cthis->name : NULL);
}

cgraph_size_t cgraph_cmdarg_namlen(const cgraph_cmdarg_t *cthis) {
  return ((NULL != cthis) ? (cthis->argv[0] - cthis->name) : 0);
}

cgraph_bool_t cgraph_cmdarg_isarg(const cgraph_cmdarg_t *cthis,
                                  const cgraph_char_t *arg) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != cthis) && CGRAPH_ISSTR(arg)) {
    CGRAPH_LOOP(i, 0, cthis->argc)
    if (cgraph_strcmp(cthis->argv[i], arg)) {
      flag = CGRAPH_TRUE;
      break;
    }
    CGRAPH_LOOP_END
  }

  return flag;
}

cgraph_size_t cgraph_cmdarg_argnum(const cgraph_cmdarg_t *cthis,
                                   const cgraph_char_t *arg) {
  cgraph_size_t num = -1;
  if ((NULL != cthis) && CGRAPH_ISSTR(arg)) {
    CGRAPH_LOOP(i, 0, cthis->argc)
    if (cgraph_strcmp(cthis->argv[i], arg)) {
      num = i;
      break;
    }
    CGRAPH_LOOP_END
  }

  return num;
}

cgraph_char_t *cgraph_cmdarg_argnam(const cgraph_cmdarg_t *cthis,
                                    const cgraph_size_t argnum) {
  return (((NULL != cthis) && (argnum < cthis->argc) && (0 <= argnum))
              ? cthis->argv[argnum]
              : NULL);
}

cgraph_size_t cgraph_cmdarg_arglen(const cgraph_cmdarg_t *cthis,
                                   const cgraph_size_t argnum) {
  return (((NULL != cthis) && (argnum < cthis->argc) && (0 <= argnum))
              ? (cthis->argv[argnum + 1] - cthis->argv[argnum] - 1)
              : 0);
}

cgraph_size_t cgraph_cmdarg_fprintln(FILE *fp, const cgraph_cmdarg_t *cthis) {
  cgraph_size_t len = 0;
  if (NULL != cthis) {
    len += cgraph_file_fprintfln(fp, "program : %s", cthis->name);
    CGRAPH_LOOP(i, 0, cthis->argc)
    len += cgraph_file_fprintfln(fp, "command %ld : %s", i, cthis->argv[i]);
    CGRAPH_LOOP_END
  }

  return len;
}
