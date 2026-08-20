// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionProximityDialogueTriggerComponent.generated.h"

/**
 * UAshenCompanionProximityDialogueTriggerComponent
 * Triggers dynamic proximity barks based on FBehavioralProfile.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionProximityDialogueTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionProximityDialogueTriggerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetProximityBarkCooldown() const { return ProximityBarkCooldown; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float ProximityBarkCooldown = 15.0f;
};
