#ifndef	ASN1_COMPILER_NAMING_H
#define	ASN1_COMPILER_NAMING_H

struct c_names {
    const char *base_name;     /* "foo" */
    const char *short_name;    /* "foo_t", "e_foo" */
    const char *full_name;     /* "struct foo", "enum foo" */
    const char *as_member;     /* "foo" (not compounded) */
    const char *presence_enum; /* "enum foo_PR" */
    const char *presence_name; /* "foo_PR" */
    const char *members_enum;  /* "enum foo" */
    const char *members_name;  /* "e_foo" */
};

struct c_names c_name(arg_t *);
const char *c_member_name(arg_t *, asn1p_expr_t *);     /* %s_%s */
const char *c_presence_name(arg_t *, asn1p_expr_t *);   /* %s_PR_%s */

/*
 * Returns 0 if no C name clashes have been encountered.
 * Returns 1 if C name clashes have been encountered.
 * Prints out the clashing items and suggests -fcompound-names.
 */
int c_name_clash(arg_t *arg);

void c_name_clash_finder_init(void);

#endif	/* ASN1_COMPILER_NAMING_H */
