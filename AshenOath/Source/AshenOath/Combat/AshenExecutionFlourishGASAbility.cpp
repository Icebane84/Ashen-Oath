// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenExecutionFlourishGASAbility.h"

UAshenExecutionFlourishGASAbility::UAshenExecutionFlourishGASAbility() {}

bool UAshenExecutionFlourishGASAbility::ExecuteStanceFinisher(uint8 StanceEnum)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenExecutionFlourishGASAbility: Stance finisher executed for stance enum %d!"), StanceEnum);
	return true;
}
