#include "TwinStickShooterPlayerState.h"
#include "Net/UnrealNetwork.h"

ATwinStickShooterPlayerState::ATwinStickShooterPlayerState()
{
	bReplicates = true;
}

void ATwinStickShooterPlayerState::CopyProperties(class APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);
	if (PlayerState)
	{
		ATwinStickShooterPlayerState* TwinStickShooterPlayerState = Cast<ATwinStickShooterPlayerState>(PlayerState);

		if(TwinStickShooterPlayerState)
			TwinStickShooterPlayerState->Name = Name;
	}
}

void ATwinStickShooterPlayerState::OverrideWith(class APlayerState* PlayerState)
{
	Super::OverrideWith(PlayerState);
	if (PlayerState)
	{
		ATwinStickShooterPlayerState* TwinStickShooterPlayerState = Cast<ATwinStickShooterPlayerState>(PlayerState);

		if (TwinStickShooterPlayerState)
			Name = TwinStickShooterPlayerState->Name;
	}
}

void ATwinStickShooterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATwinStickShooterPlayerState, Name);
}

void ATwinStickShooterPlayerState::Server_SetName_Implementation(const FString& NewName)
{
	Name = NewName;
}
bool ATwinStickShooterPlayerState::Server_SetName_Validate(const FString &NewName)
{
	return true;
}

void ATwinStickShooterPlayerState::SetName(const FString& NewName)
{
	/*
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_SetName(NewName);
    }
	else if (GetLocalRole() == ROLE_Authority && GetNetMode() == NM_ListenServer)
	{
		Name = NewName;
	}*/
	if (GetLocalRole() == ROLE_Authority && GetNetMode() == NM_ListenServer)
	{
		Name = NewName;
	}
	else
	{
		Server_SetName(NewName);
	}
}