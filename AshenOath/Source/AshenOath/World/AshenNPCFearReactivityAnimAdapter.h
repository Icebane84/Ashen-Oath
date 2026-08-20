// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCFearReactivityAnimAdapter.generated.h"

/**
 * UAshenNPCFearReactivityAnimAdapter
 * Drives civilian NPC posture blend weights when Kaelen approaches with high Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCFearReactivityAnimAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCFearReactivityAnimAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC")
	float GetNPCFearPostureWeight() const { return NPCFearPostureWeight; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC")
	float NPCFearPostureWeight = 0.0f;
};
