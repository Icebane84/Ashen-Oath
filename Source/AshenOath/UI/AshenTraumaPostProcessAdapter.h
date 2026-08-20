// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenTraumaPostProcessAdapter.generated.h"

/**
 * UAshenTraumaPostProcessAdapter
 * Modulates post-process lens desaturation, edge darkening, and high-frequency chromatic jitter scaling with Integration Debt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTraumaPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyDebtPostProcess(EIntegrationDebtStage Stage, float DebtPercent);
};
