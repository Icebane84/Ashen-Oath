// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenIntegrationDebtMasterBridge.generated.h"

/**
 * UAshenIntegrationDebtMasterBridge
 * Master bridge orchestrating synchronization between UAshenIntegrationDebtManager and all peripheral domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIntegrationDebtMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenIntegrationDebtMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bDebtBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastDebtEscalationPulse(EAshenIntegrationDebtStage Stage);
};
