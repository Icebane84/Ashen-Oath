// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenIdentityInvocationGASAbility.h"

UAshenIdentityInvocationGASAbility::UAshenIdentityInvocationGASAbility() {}

bool UAshenIdentityInvocationGASAbility::InvokeIdentityCompilationAtHeartstone()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenIdentityInvocationGASAbility: Heartstone ritual invoked — CompileIdentity(bForcedCollapse=%s)"), bForcedCollapse ? TEXT("TRUE") : TEXT("FALSE"));
	return true;
}
