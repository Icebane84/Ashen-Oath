// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenDynamicVoidFissureActor.generated.h"

/**
 * AAshenDynamicVoidFissureActor
 * 3D world hazardous void chasm actor with bottomless geometry and navmesh splitting.
 */
UCLASS()
class ASHENOATH_API AAshenDynamicVoidFissureActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenDynamicVoidFissureActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss")
	float FissureSpanUnits = 1000.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void OpenFissure();
};
