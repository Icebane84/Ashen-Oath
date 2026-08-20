// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenBestiaryFinisherMasterBridge.generated.h"

/**
 * UAshenBestiaryFinisherMasterBridge
 * Master bridge broadcasting bestiary finisher events across all domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBestiaryFinisherMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBestiaryFinisherMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bBestiaryBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastBestiaryFinisherPulse(EAshenPartyFinisherType FinisherType, AActor* TargetActor);
};
