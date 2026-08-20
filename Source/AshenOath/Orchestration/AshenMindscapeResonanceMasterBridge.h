// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMindscapeResonanceMasterBridge.generated.h"

/**
 * UAshenMindscapeResonanceMasterBridge
 * Orchestration component bridging mindscape node state transitions with SoulState vector updates.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMindscapeResonanceMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMindscapeResonanceMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bResonanceBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void SynchronizeMindscapeStateVector();
};
