// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenPartySyncFinisherMasterBridge.generated.h"

/**
 * UAshenPartySyncFinisherMasterBridge
 * Master bridge broadcasting synchronized finisher events across all domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPartySyncFinisherMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPartySyncFinisherMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bFinisherBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastFinisherPulse(EAshenPartyFinisherType FinisherType, AActor* TargetActor);
};
