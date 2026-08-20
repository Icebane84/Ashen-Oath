// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenNullZoneVolume.generated.h"

/**
 * AAshenNullZoneVolume
 * World-placed volume that actively accumulates Integration Debt and modulates MPC_NullZoneProximity post-process parameters.
 */
UCLASS()
class ASHENOATH_API AAshenNullZoneVolume : public AActor
{
	GENERATED_BODY()
public:
	AAshenNullZoneVolume();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Null Zone")
	float NullZoneRadius = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Null Zone")
	float DrainRatePerSecond = 0.05f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Null Zone")
	bool bIsPlayerInside = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Null Zone")
	float CalculateProximityRatio(FVector PlayerLocation) const;
};
