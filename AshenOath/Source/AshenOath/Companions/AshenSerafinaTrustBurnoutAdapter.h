// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaTrustBurnoutAdapter.generated.h"

/**
 * UAshenSerafinaTrustBurnoutAdapter
 * Modulates burnout dissipation rate based on pairwise trust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaTrustBurnoutAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaTrustBurnoutAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float AdjustedDissipationRate = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void UpdateBurnoutDissipationForTrust(float SerafinaTrustScore);
};
