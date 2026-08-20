// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensMasterBridge.generated.h"

/**
 * UAshenLensMasterBridge
 * Master bridge broadcasting lens selection and identity compilation events across domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLensMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLensMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bLensBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastLensSelectionPulse(EInterpretiveLens NewLens, const FSoulStateVector& CompiledVector);
};
