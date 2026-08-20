// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenScribeMemoryPinGASAbility.h"

UAshenScribeMemoryPinGASAbility::UAshenScribeMemoryPinGASAbility() {}

bool UAshenScribeMemoryPinGASAbility::ScribeMemoryPin(FVector PinLocation, FString Label, ECartographicPinType Type)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenScribeMemoryPinGASAbility: SCRIBED PIN: %s at %s (Type: %d)!"),
		*Label, *PinLocation.ToString(), static_cast<int32>(Type));
	return true;
}
