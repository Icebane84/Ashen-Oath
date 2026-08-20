// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenShadowSeepageMasterBridge.generated.h"

/**
 * UAshenShadowSeepageMasterBridge
 * Master domain bridge broadcasting corruption seepage phase shifts, bile puddle drops, and unchained static burst events across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowSeepageMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShadowSeepageMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bSeepageBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastSeepagePhaseChanged(EShadowSeepagePhase NewPhase, float CorruptionScalar);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastBilePuddleSpawned(const FVector& PuddleLocation);
};
