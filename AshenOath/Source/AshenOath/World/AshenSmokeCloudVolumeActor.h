// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSmokeCloudVolumeActor.generated.h"

/**
 * AAshenSmokeCloudVolumeActor
 * World volume actor applying blindness to foes and stealth concealment to allies.
 */
UCLASS()
class ASHENOATH_API AAshenSmokeCloudVolumeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSmokeCloudVolumeActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float CloudLifetime = 8.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void DissipateSmokeCloud();
};
