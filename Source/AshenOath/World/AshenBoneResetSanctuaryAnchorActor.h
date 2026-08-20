// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenBoneResetSanctuaryAnchorActor.generated.h"

/**
 * AAshenBoneResetSanctuaryAnchorActor
 * 3D world sanctuary anchor stabilizing Kaelen with golden light aura during the Reclamation Crash.
 */
UCLASS()
class ASHENOATH_API AAshenBoneResetSanctuaryAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenBoneResetSanctuaryAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bIsAnchorChanneling = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void ChannelGoldenStabilization();
};
