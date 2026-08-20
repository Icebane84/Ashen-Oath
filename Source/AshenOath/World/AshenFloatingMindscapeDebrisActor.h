// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenFloatingMindscapeDebrisActor.generated.h"

/**
 * AAshenFloatingMindscapeDebrisActor
 * Floating crystalline debris actor reacting to memory battle intensity.
 */
UCLASS()
class ASHENOATH_API AAshenFloatingMindscapeDebrisActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenFloatingMindscapeDebrisActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Visuals")
	float FloatSpeed = 1.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void PulseDebrisOrbit(float BattleIntensity);
};
