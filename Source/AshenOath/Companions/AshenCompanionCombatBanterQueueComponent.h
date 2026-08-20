// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionCombatBanterQueueComponent.generated.h"

/**
 * UAshenCompanionCombatBanterQueueComponent
 * Queues relational combat banter during combo executions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionCombatBanterQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionCombatBanterQueueComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	FString PopNextBanterLine();

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companion")
	float AlignmentBalance = 0.5f;
};
