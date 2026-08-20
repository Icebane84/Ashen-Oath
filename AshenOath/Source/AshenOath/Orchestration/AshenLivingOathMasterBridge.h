// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenLivingOathMasterBridge.generated.h"

/**
 * UAshenLivingOathMasterBridge
 * Master bridge broadcasting Living Oath events across all domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingOathMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingOathMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bLivingOathBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastLivingOathPulse(EAshenLivingOathType OathType, EAshenOathState State);
};
