// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSovereignPhoenixTouchstoneActor.generated.h"

/**
 * AAshenSovereignPhoenixTouchstoneActor
 * Interactive world touchstone actor commemorating Grand Master Milestone 1100 Sovereign Phoenix Ascension.
 */
UCLASS()
class ASHENOATH_API AAshenSovereignPhoenixTouchstoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSovereignPhoenixTouchstoneActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	float SovereignTouchstoneRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	bool bSovereignTouchstoneActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Touchstone")
	bool ActivateSovereignTouchstone();
};
