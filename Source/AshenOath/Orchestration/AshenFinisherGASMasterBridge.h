// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherGASMasterBridge.generated.h"

/**
 * UAshenFinisherGASMasterBridge
 * Master bridge broadcasting character GAS execution events across domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherGASMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherGASMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bFinisherGASBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastCharacterFinisherPulse(FName AbilityName, AActor* PrimaryCharacter, AActor* PartnerCharacter, AActor* TargetEnemy);
};
