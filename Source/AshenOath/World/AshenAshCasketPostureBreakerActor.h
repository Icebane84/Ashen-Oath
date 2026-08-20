// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAshCasketPostureBreakerActor.generated.h"

/**
 * AAshenAshCasketPostureBreakerActor
 * Boss posture breaker encounter actor that exposes dorsal vents and triggers Garrett's controller speaker callout ("Kaelen. Now.").
 */
UCLASS()
class ASHENOATH_API AAshenAshCasketPostureBreakerActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenAshCasketPostureBreakerActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	bool bPostureBroken = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void BreakAshCasketPosture();
};
