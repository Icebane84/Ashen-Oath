// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPhantomMirageFoeActor.generated.h"

/**
 * AAshenPhantomMirageFoeActor
 * World actor rendering illusory phantom enemy mesh dissolving into black smoke.
 */
UCLASS()
class ASHENOATH_API AAshenPhantomMirageFoeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenPhantomMirageFoeActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void DissolveMirageOnHit();
};
