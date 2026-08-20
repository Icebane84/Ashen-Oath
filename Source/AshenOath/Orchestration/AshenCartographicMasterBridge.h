// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenCartographicMasterBridge.generated.h"

/**
 * UAshenCartographicMasterBridge
 * Master domain bridge connecting world landmarks, FSoulStateVector, and Living Journal UI.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCartographicMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCartographicMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCartographicBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastLandmarkInked(const FJournalMapPin& InkedPin);
};
