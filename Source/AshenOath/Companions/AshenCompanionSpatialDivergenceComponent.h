// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionSpatialDivergenceComponent.generated.h"

/**
 * UAshenCompanionSpatialDivergenceComponent
 * Component modulating Garrett navigation offset (800uu under Cynical_Isolated) and Serafina navigation offset (550uu under Burned_Out).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSpatialDivergenceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionSpatialDivergenceComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float GarrettNavigationOffset = 300.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float SerafinaNavigationOffset = 250.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void RecalculateSpatialDivergenceOffsets(float GarrettTrust, float SerafinaTrust);
};
