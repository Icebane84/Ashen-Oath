// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSunderedMemoryBridgeActor.generated.h"

/**
 * AAshenSunderedMemoryBridgeActor
 * Shattered psychic bridge in Mindscape that dynamically reconstitutes upon Resolve channeling.
 */
UCLASS()
class ASHENOATH_API AAshenSunderedMemoryBridgeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSunderedMemoryBridgeActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	FName BridgeID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory")
	bool bIsBridgeSolidified = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	void SetBridgeReconstructed(bool bReconstructed);
};
