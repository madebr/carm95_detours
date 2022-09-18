#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "br_types.h"

extern br_token_entry(* hookvar_predefinedTokens )[457]; // addr: 005289C0

void __cdecl BrTokenBegin();

br_token __cdecl BrTokenCreate(char *identifier, br_token type);

char* __cdecl BrTokenIdentifier(br_token t);

br_token __cdecl BrTokenType(br_token t);

br_int_32 __cdecl BrTokenCount(char *pattern);

br_token __cdecl BrTokenFind(char *pattern);

br_int_32 __cdecl BrTokenFindMany(char *pattern, br_token *tokens, br_int_32 max_tokens);

br_token __cdecl BrTokenFindType(br_token *ptype, char *base, br_token *types, br_int_32 ntypes);

#endif
