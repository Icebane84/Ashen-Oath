// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCReactivityPhenotypeIntegrator.generated.h"

/**
 * UAshenNPCReactivityPhenotypeIntegrator
 * Connects NPC reactivity component to FBehavioralProfile.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCReactivityPhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCReactivityPhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC")
	float GetNPCFearFactor() const { return NPCFearFactor; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC")
	float NPCFearFactor = 0.0f;
};
