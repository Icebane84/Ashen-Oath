// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenReclamationCrashGASAbility.generated.h"

/**
 * UAshenReclamationCrashGASAbility
 * Phase 3 struggle ability: executes off-beat anti-rhythm tapping against violent haptic kickback to reset dislocated bone and snap back to humanity.
 */
UCLASS()
class ASHENOATH_API UAshenReclamationCrashGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenReclamationCrashGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Struggle")
	int32 RequiredAntiRhythmTaps = 5;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Struggle")
	bool ExecuteReclamationReset(AActor* KaelenActor);
};
