// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionSynergyPositioningDirector.generated.h"

/**
 * UAshenCompanionSynergyPositioningDirector
 * AI Director component evaluating companion formation spacing, line-of-sight, and proximity synergy buffs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSynergyPositioningDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionSynergyPositioningDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	float OptimalSynergyRadius = 450.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	float EvaluateCompanionProximitySynergy(AActor* CompanionActor);
};
