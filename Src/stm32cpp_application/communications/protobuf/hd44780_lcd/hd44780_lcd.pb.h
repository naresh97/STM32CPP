/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6-dev */

#ifndef PB_HD44780_LCD_PB_H_INCLUDED
#define PB_HD44780_LCD_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _ApiRequest_Method { 
    ApiRequest_Method_MoveCursor = 0, 
    ApiRequest_Method_WriteText = 1, 
    ApiRequest_Method_ConfigureDisplay = 2, 
    ApiRequest_Method_ShiftDisplay = 3, 
    ApiRequest_Method_ClearDisplay = 4 
} ApiRequest_Method;

typedef enum _ShiftDisplay_Direction { 
    ShiftDisplay_Direction_Left = 0, 
    ShiftDisplay_Direction_Right = 1 
} ShiftDisplay_Direction;

/* Struct definitions */
typedef struct _WriteText { 
    pb_callback_t characters;
} WriteText;

typedef struct _ApiRequest { 
    ApiRequest_Method method;
    pb_callback_t parameters;
} ApiRequest;

typedef struct _ConfigureDisplay { 
    bool DisplayOn;
    bool ShowCursor;
    bool BlinkCursor;
} ConfigureDisplay;

typedef struct _MoveCursor { 
    int32_t row;
    int32_t column;
} MoveCursor;

typedef struct _ShiftDisplay { 
    ShiftDisplay_Direction direction;
    int32_t steps;
} ShiftDisplay;


/* Helper constants for enums */
#define _ApiRequest_Method_MIN ApiRequest_Method_MoveCursor
#define _ApiRequest_Method_MAX ApiRequest_Method_ClearDisplay
#define _ApiRequest_Method_ARRAYSIZE ((ApiRequest_Method)(ApiRequest_Method_ClearDisplay+1))

#define _ShiftDisplay_Direction_MIN ShiftDisplay_Direction_Left
#define _ShiftDisplay_Direction_MAX ShiftDisplay_Direction_Right
#define _ShiftDisplay_Direction_ARRAYSIZE ((ShiftDisplay_Direction)(ShiftDisplay_Direction_Right+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ApiRequest_init_default                  {_ApiRequest_Method_MIN, {{NULL}, NULL}}
#define MoveCursor_init_default                  {0, 0}
#define WriteText_init_default                   {{{NULL}, NULL}}
#define ConfigureDisplay_init_default            {0, 0, 0}
#define ShiftDisplay_init_default                {_ShiftDisplay_Direction_MIN, 0}
#define ApiRequest_init_zero                     {_ApiRequest_Method_MIN, {{NULL}, NULL}}
#define MoveCursor_init_zero                     {0, 0}
#define WriteText_init_zero                      {{{NULL}, NULL}}
#define ConfigureDisplay_init_zero               {0, 0, 0}
#define ShiftDisplay_init_zero                   {_ShiftDisplay_Direction_MIN, 0}

/* Field tags (for use in manual encoding/decoding) */
#define WriteText_characters_tag                 1
#define ApiRequest_method_tag                    1
#define ApiRequest_parameters_tag                2
#define ConfigureDisplay_DisplayOn_tag           1
#define ConfigureDisplay_ShowCursor_tag          2
#define ConfigureDisplay_BlinkCursor_tag         3
#define MoveCursor_row_tag                       1
#define MoveCursor_column_tag                    2
#define ShiftDisplay_direction_tag               1
#define ShiftDisplay_steps_tag                   2

/* Struct field encoding specification for nanopb */
#define ApiRequest_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    method,            1) \
X(a, CALLBACK, SINGULAR, BYTES,    parameters,        2)
#define ApiRequest_CALLBACK pb_default_field_callback
#define ApiRequest_DEFAULT NULL

#define MoveCursor_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    row,               1) \
X(a, STATIC,   SINGULAR, INT32,    column,            2)
#define MoveCursor_CALLBACK NULL
#define MoveCursor_DEFAULT NULL

#define WriteText_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   characters,        1)
#define WriteText_CALLBACK pb_default_field_callback
#define WriteText_DEFAULT NULL

#define ConfigureDisplay_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     DisplayOn,         1) \
X(a, STATIC,   SINGULAR, BOOL,     ShowCursor,        2) \
X(a, STATIC,   SINGULAR, BOOL,     BlinkCursor,       3)
#define ConfigureDisplay_CALLBACK NULL
#define ConfigureDisplay_DEFAULT NULL

#define ShiftDisplay_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    direction,         1) \
X(a, STATIC,   SINGULAR, INT32,    steps,             2)
#define ShiftDisplay_CALLBACK NULL
#define ShiftDisplay_DEFAULT NULL

extern const pb_msgdesc_t ApiRequest_msg;
extern const pb_msgdesc_t MoveCursor_msg;
extern const pb_msgdesc_t WriteText_msg;
extern const pb_msgdesc_t ConfigureDisplay_msg;
extern const pb_msgdesc_t ShiftDisplay_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ApiRequest_fields &ApiRequest_msg
#define MoveCursor_fields &MoveCursor_msg
#define WriteText_fields &WriteText_msg
#define ConfigureDisplay_fields &ConfigureDisplay_msg
#define ShiftDisplay_fields &ShiftDisplay_msg

/* Maximum encoded size of messages (where known) */
/* ApiRequest_size depends on runtime parameters */
/* WriteText_size depends on runtime parameters */
#define ConfigureDisplay_size                    6
#define MoveCursor_size                          22
#define ShiftDisplay_size                        13

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
