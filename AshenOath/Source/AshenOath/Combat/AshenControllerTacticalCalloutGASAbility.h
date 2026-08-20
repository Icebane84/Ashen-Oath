// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenControllerTacticalCalloutGASAbility.generated.h"

/**
 * UAshenControllerTacticalCalloutGASAbility
 * Executes Garrett's compressed tactical timing cue through the DualSense speaker ("Kaelen. Now."), opening an actionable 1.25s sync attack window.
 */
UCLASS()
class ASHENOATH_API UAshenControllerTacticalCalloutGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenControllerTacticalCalloutGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float ActionWindowSeconds = 1.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool TriggerTacticalCallout(AActor* InstigatorActor, FName TargetEnemyID);
};
