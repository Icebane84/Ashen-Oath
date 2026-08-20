// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenTacticalAcousticEchoActor.generated.h"

/**
 * AAshenTacticalAcousticEchoActor
 * 3D world acoustic marker calculating spatial distance and occlusion between the main speakers and player controller position.
 */
UCLASS()
class ASHENOATH_API AAshenTacticalAcousticEchoActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenTacticalAcousticEchoActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float AcousticRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	float CalculateAcousticOcclusion(const FVector& ListenerLocation) const;
};
