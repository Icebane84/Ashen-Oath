// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionDialogueMasterBridge.generated.h"

/**
 * UAshenCompanionDialogueMasterBridge
 * Master bridge broadcasting dialogue events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDialogueMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionDialogueMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bDialogueBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastDialoguePulse(FName CompanionID, FString LineID);
};
