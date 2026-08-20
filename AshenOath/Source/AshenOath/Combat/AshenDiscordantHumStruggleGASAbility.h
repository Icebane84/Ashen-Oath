// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenDiscordantHumStruggleGASAbility.generated.h"

/**
 * UAshenDiscordantHumStruggleGASAbility
 * Phase 1 struggle ability: engages dual trigger locks (50% travel) and rhythmic breathing loop when corruption C >= 0.40.
 */
UCLASS()
class ASHENOATH_API UAshenDiscordantHumStruggleGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenDiscordantHumStruggleGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Struggle")
	float CorruptionActivationThreshold = 0.40f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Struggle")
	bool ActivateDiscordantHumStruggle(AActor* KaelenActor);
};
