#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Net/UnrealNetwork.h"
#include "TwinStickShooterGameState.generated.h"

UCLASS()
class TWINSTICKSHOOTER_API ATwinStickShooterGameState : public AGameState
{
	GENERATED_BODY()
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
};
