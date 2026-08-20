// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbreakerConsequenceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbreakerPenaltyApplied, float, CorruptionDelta, float, PoisePenalty);

/**
 * UAshenOathbreakerConsequenceComponent
 * Imposes psychological debt, sanity decay, and sword rebellion penalties when Kaelen fractures a sworn Living Oath.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbreakerConsequenceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathbreakerConsequenceComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Oathbreaker")
	FOnOathbreakerPenaltyApplied OnOathbreakerPenaltyApplied;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Oathbreaker")
	bool bIsSwordRebelling = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Oathbreaker")
	void ApplyOathbreakerConsequences();
};
