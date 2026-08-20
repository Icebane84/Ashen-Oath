// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Materials/MaterialParameterCollection.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Combat/AshenEmpathicNovaTypes.h"
#include "AshenUserWidget_EmpathicNovaHUD.generated.h"

/**
 * UAshenUserWidget_EmpathicNovaHUD
 * Primary UI Orchestrator for the Nova Finisher.
 * Strictly adheres to Constitutional Law #831 for Diegetic Integration and pushes FSoulStateVector to MPC_SomaticHUD.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_EmpathicNovaHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic")
	UMaterialParameterCollection* MPC_SomaticHUD;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedMutualTrust = 0.50f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedIntegrationDebt = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedSerafinaBurnout = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateNovaHUDTelemetry(float InTrust, float InDebt, float InBurnout, float InCorruption);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ApplyDiegeticHUDNoise(float IntegrationDebt);
};
