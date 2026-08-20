// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticMasterBridge.generated.h"

/**
 * UAshenSomaticMasterBridge
 * Master bridge broadcasting somatic and weapon history events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSomaticMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bSomaticBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastSomaticPulse(FName ParameterName, float Value);
};
