// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenScribeMemoryPinGASAbility.generated.h"

/**
 * UAshenScribeMemoryPinGASAbility
 * GAS ability placing a resonant psychic pin at a trauma memory echo site.
 */
UCLASS()
class ASHENOATH_API UAshenScribeMemoryPinGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenScribeMemoryPinGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	bool ScribeMemoryPin(FVector PinLocation, FString Label, ECartographicPinType Type);
};
